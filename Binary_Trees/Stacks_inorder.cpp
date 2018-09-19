#include <stdio.h>
#include <iostream>

using namespace std;


#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode{

	public:

	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;

	}

	~BinaryTreeNode()
	{
		delete left;
		delete right;

	}
};


BinaryTreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout << "Enter Data : "  ;
	cin >> rootData;


	if(rootData == -1)
		return NULL;	

	BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);

	queue< BinaryTreeNode<int>* > pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!= 0)
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter left child of " << front->data << " : ";
		int leftChildData;
		cin>>leftChildData;

		if(leftChildData != -1)
		{

			BinaryTreeNode<int> *child = new BinaryTreeNode<int> (leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}


		cout << "Enter right child of " << front->data << " : ";
		int rightChildData;
		cin>>rightChildData;

		if(rightChildData != -1)
		{

			BinaryTreeNode<int> *child = new BinaryTreeNode<int> (rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}

	}

	return root;
}


BinaryTreeNode<int> *findNode(int value, BinaryTreeNode<int>* root)
{	
	if(root == NULL)
		return NULL;

	if(root->data == value)
		return root;

	BinaryTreeNode<int>* temp = findNode(value,root->left);

	if(temp != NULL)
		return temp;

	return findNode(value,root->right);
}

//For Stack Implementation!
class LinkedList{

public:
	int data;
	LinkedList *next;
};


LinkedList *Push(LinkedList *head, int x)
{		
	LinkedList *newNode = new LinkedList;
	newNode->data = x;
	newNode->next = NULL;

	if(head == NULL)
		head = newNode;

	else
	{
		newNode->next = head;
		head = newNode;
	}

	return head;
}

LinkedList *Pop(LinkedList *head)
{
	if(head == NULL)
	{
		cout << "Can't Pop as the list is Empty";
		return NULL;
	}

	head = head->next;
	return head;
}

bool isEmpty(LinkedList *head)
{
	if(head == NULL)
		return true;
	else
		return false;
}

LinkedList *TopElement(LinkedList *head)
{
	return head;
}

void PrintStack(LinkedList *head)
{
	if(head == NULL)
		return;
	LinkedList *temp = head;

	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

void Inorder(LinkedList *head, BinaryTreeNode<int> *root)
{
	//head = Push(head,root->data); //pushing the root to the Stack!
	BinaryTreeNode<int> *temp = root;
	BinaryTreeNode<int> *prev = NULL;

	do
	{
		int flag = 0;

		while(temp != NULL)
		{
			flag = 1;
			head = Push(head,temp->data);
			prev = temp;
			temp = temp->left;
		}

		if(flag == 1)
			temp = prev;

		if(isEmpty(head) == false)
		{
			LinkedList *top = TopElement(head);
			cout << top->data << " ";
			head = Pop(head);
			BinaryTreeNode<int> *temp2 = findNode(top->data,root); 
			temp = temp2->right; //go to the right of the element Popped!
		}
	}while( isEmpty(head) == false  || temp != NULL);

	cout << endl;

}


// 1 2 3 4 -1 6 7 -1 5 8 9 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	LinkedList* head = NULL;

	Inorder(head,root);





}