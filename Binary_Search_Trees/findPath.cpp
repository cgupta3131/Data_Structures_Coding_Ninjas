#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include<iostream>
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

vector<int>* findPath(BinaryTreeNode<int> *root , int data)
{

	vector<int> *output = new vector<int>;
	if(root == NULL)
		return NULL;

	if(root->data == data)
	{
		output->push_back(root->data);
		return output;
	}


	if(root->data > data)
	{
		vector<int>* leftOutput = findPath(root->left,data);

		if(leftOutput != NULL)
		{
			leftOutput->push_back(root->data);
			return leftOutput;
		}
	}


	else
	{
		vector<int>* rightOutput = findPath(root->right,data);

		if(rightOutput!= NULL)
		{
			rightOutput->push_back(root->data);
			return rightOutput;
		}


	}

	return NULL;




}