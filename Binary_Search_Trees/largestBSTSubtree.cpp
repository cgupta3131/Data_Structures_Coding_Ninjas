#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include<iostream>
#include <climits>
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

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN ,int max = INT_MAX)
{

	if(root == NULL)
		return true;
	int root_value = root->data;

	if(root_value < min || root_value > max)
		return false;

	
	bool left = isBST3(root->left,min,root_value-1);
	bool right = isBST3(root->left,root_value,max);

	if(left == true && right == true)
		return true;
	else
		return false;
	

}

int height(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return 0;

	return 1+max( height(root->left) , height(root->right));


}

int largestBSTSubtree(BinaryTreeNode<int> *root) 
{
	if(root == NULL)
		return 0;

	int max = 0;

	if( isBST3(root,INT_MIN, INT_MAX) == true)
		return height(root);

	int left  = largestBSTSubtree(root->left);
	int right = largestBSTSubtree(root->right);

	if(left > right)
		return left;
	else 
		return right;
}

int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	cout << endl << endl << largestBSTSubtree(root) << endl;



}