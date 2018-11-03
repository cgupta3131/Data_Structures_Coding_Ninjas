#include<bits/stdc++.h>

using namespace std;

class Node{

public:
	int data;
	Node *leftChild;
	Node *rightChild;
	Node *parent;
	int height;

	Node(int data)
	{
		this->data = data;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
		height = 1; //height of leaf node being 1
	}
};



class AVLTree{

public:
	Node *head;

	AVLTree()
	{
		head=NULL;
	}

	int getHeight(Node *n)
	{
		if(n == NULL)
			return 0;
		else
			return n->height;

	}

	void InsertData(int data)
	{

		Node *newNode = new Node(data);
		if(head == NULL)
		{
			head = newNode;
			return;
		}

		Node *AddedNode = BSTInsert(data); 
		//UpdateHeights(AddedNode);
		Rebalance(AddedNode);
	}

	Node* BSTInsert(int data)
	{

		Node *temp = head;
		Node *newNode = new Node(data);




		while(1)
		{
			if(temp->leftChild == NULL && temp->rightChild == NULL)
				break;
			if(temp->data > data && temp->leftChild == NULL)
				break;
			if(temp->data < data && temp->rightChild == NULL)
				break;

			if(temp->data > data)
				temp = temp->leftChild;
			
			else
				temp = temp->rightChild;
		}

		if(temp->data > data)
			temp->leftChild = newNode;
		else
			temp->rightChild = newNode;

		newNode->parent = temp;
		
		return newNode;
	}

	void UpdateHeights(Node *AddedNode)
	{
		Node *temp = AddedNode;
		
		while(temp != NULL)
		{
			temp->height = max(getHeight(temp->leftChild),getHeight(temp->rightChild)) + 1;
			temp = temp->parent;
		}

	}

	void Rebalance(Node *newNode)
	{
		Node *temp = newNode;

		while(temp != NULL)
		{
			temp->height = max(getHeight(temp->leftChild),getHeight(temp->rightChild)) + 1;
			int balanceValue = getHeight(temp->leftChild) - getHeight(temp->rightChild);
			if(balanceValue == 2)
			{
				if( (getHeight(temp->leftChild->leftChild) - getHeight(temp->leftChild->rightChild)) >= 0 )
					temp = RotateRight(temp);
				else
				{	
					temp->leftChild = RotateLeft(temp->leftChild);
					temp = RotateRight(temp);
				}

			}

			else if(balanceValue == -2)
			{

				if( (getHeight(temp->rightChild->rightChild) - getHeight(temp->rightChild->leftChild)) >= 0 )
				{
					cout << "Rotate Left " << temp->data << endl;
					temp = RotateLeft(temp);
				}
				else
				{	
					cout << "Rotate Rotate then Left " << endl;
					temp->rightChild = RotateRight(temp->rightChild);
					temp = RotateLeft(temp);
				}
			}

			temp = temp->parent;

		}

	}

	/* 
			 y                               x
		    / \     Right Rotation          /  \
		   x   T3   – – – – – – – >        T1   y 
		  / \       < - - - - - - -            / \
		 T1  T2     Left Rotation            T2  T3
 	*/

	Node* RotateRight(Node *y)
	{
		Node *Parent_Y = y->parent;
		Node *x = y->leftChild;
		Node *T2 = x->rightChild;

		if(Parent_Y != NULL)
		{
			if(Parent_Y->leftChild == y)
				Parent_Y->leftChild = x;
			else
				Parent_Y->rightChild = x;
		}
		 

		x->parent = Parent_Y;

		y->leftChild = T2;
		if(T2 != NULL)
			T2->parent = y;

		x->rightChild = y;
		y->parent = x;

		if(Parent_Y == NULL) //Means that y was head, but Now head has to be x!
			head = x;

		y->height = max(getHeight(y->leftChild),getHeight(y->rightChild))+1;
		x->height = max(getHeight(x->leftChild),getHeight(x->rightChild))+1;

		return x;
	}


	Node *RotateLeft(Node *x)
	{
		Node *Parent_X = x->parent;
		Node *y = x->rightChild;
		Node *T2 = y->leftChild;

		if(Parent_X != NULL)
		{
			if(Parent_X->leftChild == x)
				Parent_X->leftChild = y;
			else
				Parent_X->rightChild = y;
		}

		y->parent = Parent_X;

		x->rightChild = T2;
		if(T2 != NULL)
			T2->parent = x;

		y->leftChild = x;
		x->parent = y;

		if(Parent_X == NULL) //Means that y was head, but Now head has to be x!
			head = y;


		x->height = max(getHeight(x->leftChild),getHeight(x->rightChild))+1;
		y->height = max(getHeight(y->leftChild),getHeight(y->rightChild))+1;
		

		return y;
	}

	void Inorder(Node *root)
	{
		if(root == NULL)
			return;

		Inorder(root->leftChild);

		cout << root->data << " ";
		if(root->leftChild != NULL)
			cout << "\t(" << root->leftChild->data << ")";
		else
			cout << "\t(-)";

		if(root->rightChild != NULL)
			cout << "\t(" << root->rightChild->data << ")";
		else
			cout << "\t(-)";

		cout << endl;

		Inorder(root->rightChild);
		
	}

	void Print()
	{
		Inorder(head);

	}


	void DeleteNode(int value)
	{
		Node *targetNode = BSTDelete(value);
		Rebalance(targetNode);
	}

	Node* BSTDelete(int value)
	{
		Node *myNode = head;

		while(myNode != NULL)
		{
			if(myNode->data == value)
				break;

			if(myNode->data > value)
				myNode = myNode->leftChild;
			else
				myNode = myNode->rightChild;
		}

		if(myNode->leftChild == NULL && myNode->rightChild == NULL)
		{
			Node *Parent = myNode->parent;
			if(Parent->leftChild == myNode)
				Parent->leftChild = NULL;
			else
				Parent->rightChild = NULL;

			delete myNode;

			return Parent;
		}

		else if(myNode->leftChild == NULL && myNode->rightChild != NULL)
		{
			Node *temp = myNode->rightChild;

			while(temp->leftChild != NULL)
				temp = temp->leftChild;

			myNode->data = temp->data;
			Node *Parent = temp->parent;
			if(Parent->leftChild == temp)
				Parent->leftChild = NULL;
			else
				Parent->rightChild = NULL;

			delete temp;

			return Parent;
		}

		else
		{
			Node *temp = myNode->leftChild;

			while(temp->rightChild != NULL)
				temp = temp->rightChild;

			myNode->data = temp->data;
			Node *Parent = temp->parent;
			if(Parent->leftChild == temp)
				Parent->leftChild = NULL;
			else
				Parent->rightChild = NULL;

			delete temp;

			return Parent;
		}

	}

};







int main()
{
	AVLTree *tree = new AVLTree;


	tree->InsertData(5);
	tree->InsertData(8);
	tree->InsertData(3);
	tree->InsertData(11);
	tree->InsertData(7);
	tree->InsertData(4);
	tree->InsertData(2);
	tree->InsertData(12);
	tree->InsertData(10);
	tree->InsertData(6);
	tree->InsertData(1);
	tree->InsertData(9);
	tree->DeleteNode(4);

	cout << endl;
	cout << "Data is : " << endl;
	tree->Print();
	cout << endl;



	return 0 ; 

}

