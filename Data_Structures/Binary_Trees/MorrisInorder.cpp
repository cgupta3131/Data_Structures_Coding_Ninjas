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
/*
BinaryTreeNode<int>* setRight(BinaryTreeNode<int> *temp, BinaryTreeNode<int> *p)
{
	temp->right = p;
	return temp;
}

BinaryTreeNode<int>* removeEdge(BinaryTreeNode<int> *temp, BinaryTreeNode<int> *p)
{
	temp->right = NULL;
	return temp;
}*/


void MorrisInorder(BinaryTreeNode<int> *root)
{
	BinaryTreeNode<int> *p = root;

	while(p != NULL)
	{
		if(p->left == NULL)
		{
			cout << p->data << " ";
			p = p->right;
		}


		else
		{
			BinaryTreeNode<int> *temp = p->left;

			while(temp->right != NULL && temp->right != p)
				temp = temp->right;

			if(temp->right == NULL)
			{
				temp->right = p;
				p = p->left;
			}

			else if(temp->right == p)
			{
				cout << p->data << " ";
				temp->right = NULL;
				p = p->right;
			}

		}

	}

}

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


int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	MorrisInorder(root);
}
