#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include <string.h>
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

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;

	queue< BinaryTreeNode<int>* > pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0)
	{

		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		cout << front->data << ":";


		if(front->left != NULL)
		{
			cout << "L:" << front->left->data << ",";
			pendingNodes.push(front->left);
		}

		else
			cout << "L:" << "-1" << ",";

		if(front->right != NULL)
		{
			cout << "R:" << front->right->data;
			pendingNodes.push(front->right);
		}

		else
			cout << "R:" << "-1" ;

		cout << endl;

	}

}

void Inorder(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;

	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);

}

void PreOrder(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;
	
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}



//BinaryTreeNode<int> *root
int main()
{
/*	BinaryTreeNode<int> *root = takeInputLevelWise();*/

	BinaryTreeNode<int> *root = takeInputLevelWise();
	printTreeLevelWise(root);	
	cout << endl;
	PostOrder(root);

	delete(root);

}