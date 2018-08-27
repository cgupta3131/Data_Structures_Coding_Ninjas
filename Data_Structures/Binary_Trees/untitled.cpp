#include<iostream>
#include<cstring>
#include <stack>
#include <string.h>
#include <queue>
	using namespace std;

template <typename T>
class BinaryTreeNode{

	public:

	T data;
	BinaryTreeNode* left;

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

int parentNodeData(BinaryTreeNode<int>* root, int x)
{

	if(root == NULL)
		return -1;

	if(root->data == x)
		return -1;

	if(root->left != NULL && root->left->data == x)
		return root->data;

	if(root->right != NULL && root->right->data == x)
		return root->data;

	int left = parentNodeData(root->left,x);

		if(left != -1)
			return left;

	int right = parentNodeData(root->right,x);

		if(right != -1)
			return right;

	return -1;

}


vector<int> v1;

void Helper(BinaryTreeNode<int> *root, int k )
{

	if(root->data == k && root->left == NULL && root->right == NULL)
	{
		v1.push_back(root->data);
		return;
	}


	if(root->left != NULL) 
		Helper(root->left, k - root->data);

	if(root->right != NULL)
		Helper(root->right , k - root->data);	 
	

	return;

}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) 
{	
	
	Helper(root,k);


	for(int i=0;i<v1.size();i++)
	{
		stack<int> myStack;
		int x = v1[i];
		myStack.push(x);

		while(parentNodeData(root,x) != -1)
		{
			myStack.push( parentNodeData( root,x) );
			x = parentNodeData(root,x);
		}

		while(myStack.empty() == false)
		{
			cout << myStack.top() << " ";
			myStack.pop();
		}

		cout << endl;	
	}

}	

int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	cout << endl << endl;

	rootToLeafPathsSumToK(root,13);

}

