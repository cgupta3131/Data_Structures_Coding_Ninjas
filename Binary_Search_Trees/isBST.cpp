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



BinaryTreeNode<int>* maxNode(BinaryTreeNode<int>* root)
{

	if(root == NULL)
		return NULL;

	int maxValue = root->data;
	BinaryTreeNode<int> *node = root;

	BinaryTreeNode<int> *left  = maxNode(root->left);

	if(left != NULL && left->data > maxValue)
	{
		maxValue = left->data;
		node = left;

	}


	BinaryTreeNode<int> *right = maxNode(root->right);

	if(right != NULL && right->data > maxValue)
	{
		maxValue = right->data;
		node = right;
	}


	return node;
}

BinaryTreeNode<int>* minNode(BinaryTreeNode<int>* root)
{

	if(root == NULL)
		return NULL;

	int minValue = root->data;
	BinaryTreeNode<int> *node = root;

	BinaryTreeNode<int> *left  = minNode(root->left);

	if(left != NULL && left->data < minValue )
	{
		minValue = left->data;
		node = left;

	}


	BinaryTreeNode<int> *right = minNode(root->right);

	if(right != NULL && right->data < minValue)
	{
		minValue = right->data;
		node = right;
	}


	return node;
}


bool isBST(BinaryTreeNode<int> *root)
{

	if(root == NULL)
		return true;

	BinaryTreeNode<int> *mini = minNode(root->right); // minimum Node of right tree should be greater or equal to root
	BinaryTreeNode<int> *maxi = maxNode(root->left);  // maximum Node of left tree should be less than root

	/*if(mini->data < root->data)
		return false;
	if(maxi->data >= root->data)
		return false;

	if( isBST(root->left) == false || isBST(root->right) )
		return false;*/

	if(mini == NULL || maxi == NULL)
		return true;

	if(  mini->data >= root->data &&  maxi->data < root->data && isBST(root->left) && isBST(root->right)        )
		return true;

	else
		return false;

}

int main()
{

	BinaryTreeNode<int> *root = takeInputLevelWise();
	cout << endl << endl;
	cout << isBST(root) << endl;



}
