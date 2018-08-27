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


class BST
{
	BinaryTreeNode<int>* root;


public:

	BST() //constructor
	{
		root = NULL;
	}

	~BST()
	{
		delete root;
	}

private:

	BinaryTreeNode<int>* dataToNode(int data, BinaryTreeNode<int> *root)
	{
		if(root == NULL)
			return NULL;
		if(root->data == data)
			return root;
		if(root->data > data)
			return dataToNode(data,root->left);
		else
			return dataToNode(data,root->right);
	}

	BinaryTreeNode<int>* dataToParentNode(int data, BinaryTreeNode<int> *root)
	{
		if(root == NULL)
			return NULL;
		if(root->data == data)
			return NULL;

		if(root->left != NULL && root->left->data == data )
			return root;
		if(root->right != NULL && root->right->data == data)
			return root;

		if(root->data > data)
			return dataToParentNode(data,root->left);
		else
			return dataToParentNode(data,root->right);
	}
	

	BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *root)
	{
		BinaryTreeNode<int> *node = dataToNode(data,root);

		if(node == NULL)
			return NULL;

		if(root->data == data && root->left == NULL && root->right == NULL)
			return NULL;
		if(root->data == data && root->left != NULL && root->right == NULL)
			return root->left;
		if(root->data == data && root->left == NULL && root->right != NULL)
			return root->right;

		if(node->right != NULL && node->left != NULL )  
		{
			BinaryTreeNode<int> *temp = node->right;
			BinaryTreeNode<int> *prev = NULL;
			while(temp->left != NULL)
			{
				prev = temp;
				temp = temp->left;
			}

			node->data = temp->data;

			if(prev != NULL)
			{
				prev->left = temp->right;
				return root;
			}

			else if(prev == NULL)
			{

				node->right = temp->right;	
				return root;
			}
		}

		else if(node->right != NULL && node->left == NULL)
		{	

			BinaryTreeNode<int> *parentNode = dataToParentNode(data,root);

			if(parentNode->left != NULL && parentNode->left->data == data)
			{

				parentNode->left = node->right;
				node->right = NULL;
				return root;

			}
			else
			{	
				parentNode->right = node->right;
				node->right = NULL;
				return root;
			}

		}

		else if(node->right == NULL && node->left != NULL)
		{	
			BinaryTreeNode<int> *parentNode = dataToParentNode(data,root);

			if(parentNode->left != NULL && parentNode->left->data == data)
			{
				parentNode->left = node->left;
				node->left = NULL;
				return root;

			}
			else
			{
				parentNode->right = node->left;
				node->left = NULL;
				return root;
			}

		}

		else if(node->right == NULL && node->left == NULL)//leaf node
		{

			BinaryTreeNode<int> *parentNode = dataToParentNode(data,root);

			if(parentNode->left != NULL && parentNode->left->data == data)
				parentNode->left = NULL;
			else
				parentNode->right = NULL;

			return root;
		}

	}

	
public:
	void deleteData(int data)
	{
		root = deleteData(data,root);

	}

private:
	BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int> *root)
	{
		if(root == NULL)
		{
			BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
			return node;
		}

		else if(data > root->data )
			root->right = insert(data,root->right);

		else
			root->left = insert(data,root->left);
		
		return root;

	}


public:
	void insert(int data)
	{
		root = insert(data,root);
	}

private:
	bool hasData(int data, BinaryTreeNode<int> *root)
	{
		if(root == NULL)
			return false;

		if(root->data == data)
			return true;

		else if(root->data > data)
			return hasData(data,root->left);
		else
			return hasData(data,root->right);	
	}


public:
	bool hasData(int data)
	{
		return hasData(data,root);
	}


private:
	void printTree(BinaryTreeNode<int> *root)
	{
		if(root == NULL)
			return;
		cout << root->data << ":";
		if(root->left != NULL)
			cout << "L:" << root->left->data << ",";
		if (root->right!=NULL)
     	    cout << "R:" << root->right->data;

     	cout << endl;
    	printTree(root->left);
    	printTree(root->right);
	}

public:
	void printTree()
  	{
    	printTree(root);
  	}


};


int main()
{
	BST b;
	b.insert(20);
	b.insert(15);
	b.insert(14);
	b.insert(13);
	cout << endl << endl;

	b.printTree();
	int x;
	cin >> x;
	b.deleteData(x);	

	b.printTree();


}