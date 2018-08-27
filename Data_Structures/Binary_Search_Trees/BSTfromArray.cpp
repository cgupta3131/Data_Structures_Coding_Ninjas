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


BinaryTreeNode<int>* constructTreeHelper(int *input, int si, int ei)
{
	int length = ei-si+1;

	if(length <=0)
		return NULL;
	int mid = (si+ei)/2;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int> (input[mid]);

	
	root->left = constructTreeHelper(input,si,mid-1);
	root->right = constructTreeHelper(input,mid+1,ei);	

	return root;



}


BinaryTreeNode<int>* constructTree(int *input, int n) 
{
	return constructTreeHelper(input,0,n-1);
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

int main()
{
	int input[] = {1,2,3,4,5,6,7};
	int n = sizeof(input)/sizeof(input[0]);

	BinaryTreeNode<int>* root = constructTree(input,n);
	printTreeLevelWise(root);



}