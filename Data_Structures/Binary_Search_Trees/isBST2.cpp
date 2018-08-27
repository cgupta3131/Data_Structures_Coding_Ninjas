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


class isBSTReturn{

public:
	bool isBST;
	int minimum;
	int maximum;

};


isBSTReturn isBST2(BinaryTreeNode<int> *root)
{
	isBSTReturn output;

	if(root == NULL)
	{
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MAX;

		return output;
	}

	isBSTReturn left =  isBST2(root->left);
	isBSTReturn right = isBST2(root->right);

	bool isBST_final = (left.max < root->data) && (right.min >= root->data) && (left.isBST == true) && (right.isBST == true);

	output.isBST = isBST_final;
	output.minimum = min(root->data, min(left.min,right.min));
	output.maximum = max(root->data, man(left.max,right.max));

	return output;

}