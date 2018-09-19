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




BinaryTreeNode<int>* intToNode(BinaryTreeNode<int>* root, int x)
{
	if(root == NULL)
		return NULL;
	if(root->data == x)
		return root;

	BinaryTreeNode<int>* left  = intToNode(root->left,x);
		if(left != NULL)
			return left;
	BinaryTreeNode<int>* right = intToNode(root->right,x);
		if(right != NULL)
			return right;

	return NULL;

}

bool isPresent(	BinaryTreeNode<int>* root, int x)
{
	if(root == NULL)
		return false;

	if(root->data == x)
		return true;

	bool left = isPresent(root->left,x);
	bool right = isPresent(root->right,x);

	if(left == true || right == true)
		return true;
	else
		return false;
}


int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2)
{

	BinaryTreeNode<int>* first = intToNode(root,val1);
	BinaryTreeNode<int>* second = intToNode(root,val2);

	if(first == NULL && second != NULL)
		return val2;

	else if(first != NULL && second == NULL)
		return val1;

	else if(first == NULL && second == NULL)
		return -1;

	if(root == first || root == second)
		return root->data;


	if(  isPresent(root->left,val1) == true && isPresent(root->right,val2) == true) //present in different branches
		return root->data;

	if(  isPresent(root->right,val1) == true && isPresent(root->left,val2) == true ) //present in different branches
		return root->data;

	if(  isPresent(root->left,val1) == true && isPresent(root->left,val2) == true)
		return lcaBinaryTree(root->left,val1,val2);		

	if(  isPresent(root->right,val1) == true && isPresent(root->right,val2) == true)
		return lcaBinaryTree(root->right,val1,val2);

	return 0;		
	

}


int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	cout << endl << endl;

	int val1, val2;
	cout << "Enter value 1 : ";
	cin >> val1;

	cout << "Enter value 2 : ";
	cin >> val2;

	cout << endl << endl;
	cout << lcaBinaryTree(root,val1,val2) << endl;

}