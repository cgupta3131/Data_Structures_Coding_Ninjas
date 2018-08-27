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


int height(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return 0;

	int total=1;

	int leftheight = height(root->left);
	int rightheight = height(root->right);

	if(leftheight>=rightheight)
		total += leftheight;
	else
		total += rightheight;

	return total;

}

int diameter(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return 0;

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);

	return max(option1 , max(option2,option3));

}

pair<int, int>heightDiameter(BinaryTreeNode<int> *root)
{
	if(root == NULL)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int, int> rightAns = heightDiameter(root->right);

	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;

	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh,max(ld,rd));

	pair<int,int> p;
	p.first = height;
	p.second = diameter;

	return p;



}


int main()
{

	BinaryTreeNode<int>* root = takeInputLevelWise();
	pair<int, int> p = heightDiameter(root);
	cout << p.first << " " << p.second << endl;



}