#include <iostream>
using namespace std;

class ThreadNode{

public:
	int data;
	ThreadNode* left;
	ThreadNode* right;
	bool rightThread;

	ThreadNode(int data)
	{
		this->data  = data;
		this->left  = NULL;
		this->right = NULL;
		this->rightThread = false;
	}

};

ThreadNode* leftMost(ThreadNode* root)
{
	if(root == NULL)
		return NULL;

	while(root->left != NULL)
		root = root->left;

	return root;
}



void Inorder(ThreadNode* root)
{
	if(root == NULL)
		return ;

	ThreadNode* temp = leftMost(root);

	
	while(temp != NULL)
	{
		cout << temp->data << " ";

		if(temp->right != NULL && temp->rightThread == false)
			temp  = leftMost(temp->right);
		else
			temp = temp->right;

	}

	cout << endl;
}

void PreOrder(ThreadNode *root)
{
	if(root == NULL)
		return;
	ThreadNode *prev = NULL;

	while(root != NULL)
	{
		cout << root->data << " ";
		prev = root;
		root =  root->left;	

		while(root->right != NULL && root->rightThread == true)
			root = root->right;

		if(root != NULL)
			root = root->right;	
	}
}


ThreadNode *findNode(int value, ThreadNode* root)
{	
	if(root == NULL)
		return NULL;

	if(root->data == value)
		return root;

	ThreadNode* temp = findNode(value,root->left);

	if(temp != NULL)
		return temp;

	else if(root->rightThread == false)
		return findNode(value,root->right);

	return NULL;

}

void PrintTree(ThreadNode *root)
{
	if(root == NULL)
		return;

	cout << root->data << " ";


	if(root->left != NULL)
		cout << "L :" << root->left->data;

	if(root->right != NULL && root->rightThread == false)
		cout << "R :"  << root->right->data;
	cout << endl;

	PrintTree(root->left);
	if(root->rightThread == false)
		PrintTree(root->right);
 
}



int main()
{
	int data;
	cout << "Enter root data : ";
	cin >> data;

	ThreadNode *root = new ThreadNode(data);

	int n;
	cout << "Enter Number of Nodes : ";
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int data;
		cout << "Enter node data : ";
		cin >> data;
		ThreadNode *node = new ThreadNode(data);


		int value;
		cout << "At which node you want to add the data : ";
		cin >> value;
		ThreadNode *finded = findNode(value,root);

		char side;
		cout << "Which side you want to add " << data << " : ";
		cin >> side;


		if(side == 'L')
		{
			finded->left = node;
			node->right = finded;
			node->rightThread = 1;
		}


		else
		{
			node->right = finded->right;
			finded->right = node;
			if(finded->rightThread ==  true)
			{
				finded->rightThread = false;
				node->rightThread = true;
			}
		}

	}
	cout << endl << endl;
	PrintTree(root);
	cout << endl << endl;
	Inorder(root);
	cout << endl << endl;
	PreOrder(root);




}