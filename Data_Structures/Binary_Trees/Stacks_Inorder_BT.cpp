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
	return NULL;
}

class LinkedList{

public:
	int data;
	LinkedList *next;
};




LinkedList* Push(LinkedList* head, int x)
{
	if(head == NULL)
	{
		LinkedList *node = new LinkedList;
		node->data = x;
		node->next = NULL;
		return node;
	}


	LinkedList *node = new LinkedList;
	node->data = x;
	node->next = head;

	head = node;

	return head;

}

LinkedList* Pop(LinkedList* head)
{
	if(head == NULL)
	{
		cout << "Can't pop an element as stack is empty" << endl;
		return NULL;
	}

	LinkedList *temp = head;
	head = head->next;
	delete(temp);

	return head;


}

bool isEmpty(LinkedList *head)
{
	if(head == NULL)
		return true;
	else
		return false;

}

LinkedList* TopElement(LinkedList *head)
{
	return head;
}

void PrintStack(LinkedList* head)
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
	return;

}

void Inorder(LinkedList *head, BinaryTreeNode<int> *root)
{

	BinaryTreeNode<int> *prev = NULL;
	BinaryTreeNode<int> *temp = root;

	while(temp != NULL || isEmpty(head) == false)
	{

		while(temp!= NULL)
		{
			head = Push(head,temp->data);
			prev = temp;
			temp = temp->left;
		}

		temp = prev;

		cout << TopElement(head)->data << " " << endl;
		temp = findNode(TopElement(head)->data,root);
		head = Pop(head);

		temp = temp->right;

	}

}




int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	LinkedList* head = NULL;

	Inorder(head,root);





}