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



bool isPresent(	BinaryTreeNode<int>* root, int x)
{
	if(root == NULL)
		return false;

	if(root->data == x)
		return true;

	if(root->data > x)
		return isPresent(root->left,x);
	else
		return isPresent(root->right,x);

}


int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2)  // the first node with value between val1 and val2 is my 
															   // LCA for BST!!!!!
{
	bool first = isPresent(root,val1);
	bool second = isPresent(root,val2);

	if(first == false && second == true)
		return val2;

	else if(first == true && second == false)
		return val1;

	else if(first == false && second == false)
		return -1;

	if(root->data == val1 || root->data == val2)
		return root->data;



	int maxi = max(val1,val2);
	int mini = min(val1,val2);


	if(root->data > mini && root->data < maxi )
		return root->data;

	if(root->data > maxi)
		return lcaInBST(root->left,val1,val2);

	

	if(root->data < mini)
		return lcaInBST(root->right,val1,val2);





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
	cout << lcaInBST(root,val1,val2) << endl;

}
