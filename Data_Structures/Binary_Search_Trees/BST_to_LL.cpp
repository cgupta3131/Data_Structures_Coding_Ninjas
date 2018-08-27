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

template <typename T>
class Node{

public:
	T data;
	Node* next;

	Node(T data)
	{
		this->data = data;
		this->next = NULL;

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



Node<int>* constructBST(BinaryTreeNode<int>* root) 
{
	if(root == NULL)
		return NULL;

	Node<int> *mid = new Node<int>(root->data);

	Node<int>* leftLL  = constructBST(root->left);
	Node<int>* rightLL = constructBST(root->right);

	mid->next = rightLL;
	
	if(leftLL == NULL)
		return mid;
	
	Node<int> *temp = leftLL;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = mid;

	return leftLL;

}


int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	Node<int>* head = constructBST(root);

	Node<int>* temp = head;

	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;

	}


}