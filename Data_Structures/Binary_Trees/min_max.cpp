#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include <string.h>
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


class PairAns {
    public :
        int min;
        int max;
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

PairAns minMax(BinaryTreeNode<int> *root)
{
	PairAns temp;

	if(root == NULL)
	{
		temp.min = 1000;
		temp.max = -1;
		return temp;	
	}

	PairAns leftTree  = minMax(root->left);
	PairAns rightTree = minMax(root->right);

	int min_value = min(leftTree.min, min(rightTree.min,root->data) );
	int max_value = max(leftTree.max , max(rightTree.max, root->data) );

	temp.min = min_value;
	temp.max = max_value;

	return temp;

}	

int main()
{
	BinaryTreeNode<int>* root = takeInputLevelWise();
	PairAns value = minMax(root);

	cout << value.min << " " << value.max << endl ;

}