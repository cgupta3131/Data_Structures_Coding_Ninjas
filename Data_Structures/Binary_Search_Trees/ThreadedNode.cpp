#include <iostream>

using namespace std;

class ThreadNode{

public:
	int data;
	ThreadNode* left;
	ThreadNode* right;
	bool rightThread;
};


ThreadNode *mkNode(int value)
{
	ThreadNode *root = new ThreadNode;
	root->data = value;
	root->left = NULL;
	root->right = NULL;
	root->rightThread = false;

	return root;
}


ThreadNode* leftMost(ThreadNode* root)
{
	if(root== NULL)
		return NULL;

	while(root->left != NULL)
		root =  root->left;

	return root;
}

ThreadNode* leftMost2(ThreadNode* root)
{
	if(root== NULL)
		return NULL;

	while(root->left != NULL)
	{
		cout << root->data << " ";
		root =  root->left;
	}

	cout << root->data << " ";
	return root;
}

void inorder2(ThreadNode* root)
{
	ThreadNode* cur = leftMost(root);
	while(cur != NULL)
	{	
		cout << cur->data << " ";
		if(cur->rightThread == true)
			cur = cur->right;
		else
			cur = leftMost(cur->right);
	}
	
}
void inorder3(ThreadNode* root)
{
	if(root == NULL)
		return;
	inorder3(root->left);
	cout << root->data << " ";
	if(root->rightThread == 0)
		inorder3(root->right);
}


ThreadNode* find2(ThreadNode* root, int value)
{
	if(root == NULL)
		return NULL;
	if(root->data == value)
		return root;

	ThreadNode* temp = find2(root->left,value);
	if(temp != NULL)
		return temp;

	if(root->rightThread == 0)
		return find2(root->right,value);
}

void printTree(ThreadNode *root)
{
	if(root == NULL)
		return;

	cout << root->data << " ";

	if(root->left != NULL)
		cout<< "L :" << root->left->data;

	if(root->right != NULL && root->rightThread == 0)
		cout<< "R :" << root->right->data;
	cout << endl;

	printTree(root->left);
	if(root->rightThread == 0)
		printTree(root->right);

}


int main()
{
	int a,b;
	char c;

	cin >> a >> b >> c;

	ThreadNode* root = mkNode(b);
	int n;

	cout << "Enter number of Nodes" << endl;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int a,b;
		char c;
		cin >> a >> b >> c;

		ThreadNode *first = find2(root,a);
		ThreadNode *second = mkNode(b);

		if(c == 'L')
		{
			first->left = second;
			second->right = first;
			second->rightThread = 1;
		}

		else
		{
			second->right = first->right;
			first->right = second;

			second->rightThread =1;
			first->rightThread =0; 
		}

	}


	printTree(root);



}