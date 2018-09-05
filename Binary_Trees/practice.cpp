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
	
int sumOfAllNodes(BinaryTreeNode<int>* root) 
{
	if(root == NULL)
		return 0;
	return (root->data) + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);

}

int height(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return 0;

	int height1 = height(root->left);
	int height2 = height(root->right);

	return 1+max(height1,height2); 
}

bool isBalanced(BinaryTreeNode<int> *root) 
{
	if(root == NULL)
		return true;

	int height1 = height(root->left);
	int height2 = height(root->right);

	int diff = height1 - height2;

	if(diff == 0 || diff == 1 || diff == -1  )
	{
		bool ans1 = isBalanced(root->left);
		bool ans2 = isBalanced(root->right);

		if(ans1 == false || ans2 == false)
			return false;
		else
			return true;
	}

	else
		return false;	

}


BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) 
{
	if(root == NULL)
		return NULL;

	if(root->left == NULL && root->right == NULL)
	{
		delete root;
		return NULL;
	}

	root->left = removeLeafNodes(root->left);
	root->right = removeLeafNodes(root->right);


	return root;
}


void printLevelATNewLine(BinaryTreeNode<int> *root) 
{
	if(root == NULL)
		return;

	queue<BinaryTreeNode<int> *> q1;
	q1.push(root);

	while(q1.size() != 0)
	{
		int temp = q1.size();
		for(int i=0;i<temp;i++)
		{
			cout << q1.front()->data<< " ";
			if(q1.front()->left != NULL)
				q1.push(q1.front()->left );

			if(q1.front()->right != NULL)
				q1.push(q1.front()->right );

			q1.pop();
		}


		cout << endl;

	}

}

void zigZagOrder(BinaryTreeNode<int> *root) 
{
	if(root == NULL)
		return;

	queue<BinaryTreeNode<int> *> q1;
	q1.push(root);

	int flag = 0; // 0 denotes odd and 1 denotes even


	while(q1.size() != 0)
	{
		int temp = q1.size();



		if(flag == 0) //odd row
		{
			for(int i=0;i<temp;i++)
			{
				cout << q1.front()->data<< " ";
				if(q1.front()->left != NULL)
					q1.push(q1.front()->left );

				if(q1.front()->right != NULL)
					q1.push(q1.front()->right );

				q1.pop();
			}

			flag = 1;

		}


		else
		{
			stack<BinaryTreeNode<int> *> s1;

			for(int i=0;i<temp;i++)
			{	
				
				if(q1.front()->left != NULL)
					q1.push(q1.front()->left );

				if(q1.front()->right != NULL)
					q1.push(q1.front()->right );

				s1.push( q1.front() );
				q1.pop();	
			}

			while(s1.size() != 0)
			{
				cout << s1.top()->data << " ";
				s1.pop();
			}

			flag = 0;

		}

		
		cout << endl;

	}

}


void nodesWithoutSibling(BinaryTreeNode<int> *root) 
{

	if(root == NULL)
		return;

	if(root->left == NULL && root->right != NULL)
		cout << root->right->data << endl;

	if(root->left != NULL && root->right == NULL)
		cout << root->left->data << endl;

	nodesWithoutSibling(root->left);
	nodesWithoutSibling(root->right);




}


int main()
{
	BinaryTreeNode<int>* root = takeInputLevelWise();
	/*cout << isBalanced(root) << endl;*/

	cout << endl << endl << endl;
	nodesWithoutSibling(root);

}