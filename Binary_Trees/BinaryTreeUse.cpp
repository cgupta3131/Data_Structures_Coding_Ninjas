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

void printTree(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;
	cout << root->data << " : ";

	if(root->left != NULL)
	{
		cout << "L" << root->left->data << "," ; 

	}

	if(root->right != NULL)
	{
		cout << "R" << root->right->data; 

	}

	cout << endl;
	printTree(root->left);
	printTree(root->right);

}

BinaryTreeNode<int>* takeInput()
{
	int rootData;
	cout << "Enter Data : "  ;
	cin >> rootData;

	if(rootData == -1)
		return NULL;

	BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);
	BinaryTreeNode<int> *leftChild = takeInput();
	BinaryTreeNode<int> *rightChild = takeInput();

	root->left = leftChild;
	root->right= rightChild;

	return root;


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

int countNodes(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);

}

bool isNodePresent(BinaryTreeNode<int>* root, int x) 
{


	if(root->data == x)
		return true;

	if(root->left != NULL)
	{
		bool temp = isNodePresent(root->left,x);
		if(temp == true)
			return true;

	}

	if(root->right != NULL)
	{
		bool temp = isNodePresent(root->right,x);
		if(temp == true)
			return true;
	}

	return false;
}


int height(BinaryTreeNode<int> *root)
{

	if(root == NULL)
		return 0;

		int a = height(root->left);
		int b = height(root->right);

		if(a>b)
			return 1+a;
		else
			return 1+b;

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

void mirrorBinaryTree(BinaryTreeNode<int>* root) 
{

	if(root == NULL)
		return;

	BinaryTreeNode<int> *temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);

}

//BinaryTreeNode<int> *root
int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();

	cout << height(root) << endl;


	delete(root);

}
