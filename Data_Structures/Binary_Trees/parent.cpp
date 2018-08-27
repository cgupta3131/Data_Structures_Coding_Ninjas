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

int depthOfaNode(BinaryTreeNode<int> *root, int x)
{
	if(root == NULL)
		return 0;

	if(root->data == x)
		return 1;


	int left = depthOfaNode(root->left,x);
	int right = depthOfaNode(root->right,x);

	if(left != 0)
		return 1+left;

	else if(right != 0)
		return 1+right;

	else 
		return 0;
}

BinaryTreeNode<int>* par(BinaryTreeNode<int>* root, int x)
{

	if(root == NULL)
		return NULL;

	if(root->data == x)
		return NULL;

	if(root->left != NULL && root->left->data == x)
		return root;

	if(root->right != NULL && root->right->data == x)
		return root;



	BinaryTreeNode<int> *left  = par(root->left,x);

		if(left != NULL)
			return left;

	BinaryTreeNode<int> *right = par(root->right,x);
		if(right != NULL)
			return right;

	return NULL;

}




int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();	

	cout << endl << endl;	
	cout << par(root,5)->data << endl;



}