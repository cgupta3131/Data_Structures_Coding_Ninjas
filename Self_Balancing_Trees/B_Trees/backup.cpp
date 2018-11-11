//It will split only if it is necessary that is it will first go to the Leaf Node 
//where we want to insert the element, if that Node is full, then it will split
//it and push the median upwards. (Bottom-Up Approach)

#include<bits/stdc++.h>

using namespace std;

class Node{

public:
	int *keys; //Array of keys
	int t; //Minimum Order -> Defines the range for number of keys
	Node **child; //Array of Child Pointers
	int n; //Number of keys present in the Node;
	bool isLeaf; 
	Node* parent;

	Node(int t, bool isLeaf, Node* parent)
	{
		this->t = t;
		this->isLeaf = isLeaf;
		this->parent = parent;

		keys = new int[2*t-1]; //as Maximum number of keys could be 2t-1;
		child = new Node* [2*t]; //as Maximum number of children could be 2t;
		n = 0; //Inital Number of keys present in the Node is Zero
	}


	Node *LeafNode(int k)
	{
		if(isLeaf == true)
			return this;

		int i=0;
		while(i<n && k > keys[i])
			i++;

		return child[i]->LeafNode(k);
	}

	//Will be called only when the Node is not Full and is a Leaf Node
	void InsertLeafNode(int k)
	{
		int i = n-1;

		while(i>=0 && keys[i] > k)
		{
			keys[i+1] = keys[i];
			i--;
		}

		keys[i+1] = k;
		n++;
	}

	void Split(Node **root)
	{	

		Node *z = new Node(t,isLeaf,parent);
		z->n = t-1;

		for(int j=0;j<t-1;j++)
			z->keys[j] = this->keys[j+t];

		if(this->isLeaf == false)
		{
			for(int j=0;j<t;j++)
				z->child[j] = this->child[j+t];
		}

		this->n = t-1;
		for(int j=0;j<t-1;j++)
			this->keys[j+t] = 0;

		int temp = this->keys[t-1];
		this->keys[t-1] = 0;

		if(parent->n != (2*t-1))	
		{

			int i;
			for(i=0;i<=parent->n;i++) //As number of children are 1 more than
			{						  //number of keys in a Node
				if(parent->child[i] == this)
					break;
			}


			for (int j = parent->n; j >= i+1; j--)
				parent->child[j+1] = parent->child[j];

			parent->child[i+1] = z;	

			for(int j=parent->n;j>i;j--)
				parent->keys[j+1] = parent->keys[j];

			parent->keys[i] = temp;
			parent->n += 1;

		}


		else
		{

			if(parent->parent != NULL) //The parent is not Root
				parent->Split(root);
			else
				parent->rootSplit(root); //This means that the parent is root

			cout << parent->keys[0] << endl;


			int i;
			for(i=0;i<=parent->n;i++) //As number of children are 1 more than
			{						  //number of keys in a Node
				if(parent->child[i] == this)
					break;
			}


			for (int j = parent->n; j >= i+1; j--)
				parent->child[j+1] = parent->child[j];

			parent->child[i+1] = z;	

			for(int j=parent->n;j>i;j--)
				parent->keys[j+1] = parent->keys[j];

			parent->keys[i] = temp;
			parent->n += 1;
		}	
	}

	void rootSplit(Node **root)
	{	
		Node *s;
		s = new Node(t,false,NULL);
		s->child[0] = this;
		this->parent = s;

		Node *z = new Node(t,isLeaf,parent);
		z->n = t-1;

		for(int j=0;j<t-1;j++)
			z->keys[j] = this->keys[j+t];


		if(this->isLeaf == false)
		{
			for(int j=0;j<t;j++)
				z->child[j] = this->child[j+t];
			
			cout << z->child[1]->keys[1] << endl;
		}

		cout << z->child[1]->keys[1] << endl;


		this->n = t-1;
		for(int j=0;j<t-1;j++)
			this->keys[j+t] = 0;

		int i;
		for(i=0;i<=parent->n;i++) //As number of children are 1 more than
		{						  //number of keys in a Node
			if(parent->child[i] == this)
				break;
		}

		for(int j=parent->n;j>i;j--)
			parent->keys[j+1] = parent->keys[j];

		parent->keys[i] = this->keys[t-1];
		this->keys[t-1] = 0;

		for (int j = parent->n; j >= i+1; j--)
			parent->child[j+1] = parent->child[j];

		parent->child[i+1] = z;


		parent->n += 1;
		

		*root=s;
	}

};


class BTree{

public:
	Node *root;
	int t;

	BTree(int t)
	{
		this->t = t;
		root=NULL;
	}

	void InsertNode(int k)
	{
		//If Tree is Empty!
		if(root == NULL)
		{	
			root = new Node(t,true,NULL);
			root->keys[0] = k;
			root->n = 1;

			return;
		}

		else
		{	
			Node *TargetNode;
			if(root->isLeaf == true)
				TargetNode = root;
			else
				TargetNode = root->LeafNode(k);

			if( TargetNode->n != (2*t-1) )
				TargetNode->InsertLeafNode(k);

			else
			{
				if(TargetNode != root)
					TargetNode->Split(&root);
				else
					TargetNode->rootSplit(&root);

				TargetNode =root->LeafNode(k);
				TargetNode->InsertLeafNode(k);
			}
		}

		
		
	}
};


int main()
{
	BTree t(2);
	t.InsertNode(2);	
	t.InsertNode(6);
	t.InsertNode(7);
	t.InsertNode(3);
	t.InsertNode(4);
	t.InsertNode(12);
	t.InsertNode(14);	
	t.InsertNode(8);
	t.InsertNode(10);
	t.InsertNode(20);
	t.InsertNode(21);
	t.InsertNode(15);
	t.InsertNode(18);
	t.InsertNode(23);
	t.InsertNode(25);

	
	t.InsertNode(13);

	cout << t.root->child[0]->keys[0] << " ";
	cout << t.root->child[0]->keys[1] << " ";
	cout << t.root->child[0]->keys[2] << " ";

	return 0 ; 

}

