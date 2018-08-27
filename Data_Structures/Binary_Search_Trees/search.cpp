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


BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k)
{
	if(root == NULL)
		return NULL;

	if(root->data == k)
		return root;

	if(k>root->data)
		return searchInBST(root->right,k);
	else
		return searchInBST(root->left,k);


}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) 
{
if(root == NULL)
		return;

	if(k1 < root->data)
		elementsInRangeK1K2(root->left,k1,k2);

	if(root->data >= k1 && root->data <= k2)
		cout << root->data << " ";

	if(k2 > root->data)
		elementsInRangeK1K2(root->right,k1,k2);
}



int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();

	elementsInRangeK1K2()

}