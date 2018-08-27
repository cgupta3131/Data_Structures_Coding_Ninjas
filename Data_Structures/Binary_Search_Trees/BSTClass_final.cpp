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

	BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *root)
	{
		if(root == NULL)
			return NULL;

		if(root->data == data)
		{
			if(root->left == NULL && root->right == NULL)
				return NULL;

			if(root->left == NULL && root->right != NULL)
			{	
				BinaryTreeNode<int> *temp = root->right;
				delete root;
				return temp;
			}

			if(root->left != NULL && root->right == NULL)
			{	
				BinaryTreeNode<int> *temp = root->left;
				delete root;
				return temp;
			}

			if(root->left != NULL && root->right != NULL)
			{
				BinaryTreeNode<int> *temp2 = root->right;
		
				while(temp2->left != NULL)
					temp2 = temp2->left;
				
		        int rightmin = temp2->data;

		        BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(rightmin);

		        temp->right = deleteData(rightmin,root->right);
		        temp->left = root->left;
		        
		        delete root;
		        return temp;
			}

		}

		if(root->data > data)
		{
			BinaryTreeNode<int> *left = deleteData(data,root->left);
			root->left = left;
			return root;
		}
		else if(root->data < data)
		{
			BinaryTreeNode<int>* right = deleteData(data,root->right);
			root->right = right;
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