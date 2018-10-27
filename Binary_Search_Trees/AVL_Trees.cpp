#include<bits/stdc++.h>

using namespace std;

class AVL_Tree_Node{

public:

	int data;
	AVL_Tree_Node* left;
	AVL_Tree_Node* right;
	int height;

	AVL_Tree_Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL; //new node added as leaf initially!
		height = 1;

	}

};

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int height(AVL_Tree_Node *node)
{
	if(node == 0)
		return 0;
	return node->height;
}

AVL_Tree_Node *rightRotate(AVL_Tree_Node *y)
{

	AVL_Tree_Node *x = y->left;
	AVL_Tree_Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	x->height = max( height(x->left), height(x->right) ) + 1; 
	y->height = max( height(y->left), height(y->right) )  + 1;  

	return x;
}



AVL_Tree_Node *leftRotate(AVL_Tree_Node *x)
{

	AVL_Tree_Node *y = x->right;
	AVL_Tree_Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max( height(x->left), height(x->right) ) + 1; 
	y->height = max( height(y->left), height(y->right) )  + 1; 

	return y;
}

int getBalance(AVL_Tree_Node *node)
{
	if(node == NULL)
		return 0;

	return height(node->left) - height(node->right);
}


AVL_Tree_Node *Insert(AVL_Tree_Node *node, int key)
{
	if(node == NULL)
	{
		AVL_Tree_Node *Node =  new AVL_Tree_Node(key);
			return Node;
	}


	if(key < node->data) 
		node->left = Insert(node->left,key);

	if(key > node->data) 
		node->right = Insert(node->right,key);

	//cout << "hey" << endl;
	//Update the Height of this ancestor Node
	node->height = 1 + max(height(node->left), height(node->right));

	//get the balance factor of this node to check whether this node has got unbalanced
	//or not
	int balance = getBalance(node); 
	//cout << "Balance : " << balance << endl;


	//Left Left Case
	 if (balance > 1 && key < node->left->data) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->data) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->data) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->data) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    return node;
}

void inOrder(AVL_Tree_Node *root) 
{ 
    if(root != NULL) 
    { 
    	inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right); 
    } 

}



int main()
{
	AVL_Tree_Node *root = NULL;	
	root = Insert(root,10);

	root = Insert(root,20); inOrder(root);cout << endl;
	root = Insert(root,30); 
	root = Insert(root,40); 
	root = Insert(root,50); 
	root = Insert(root,25); 

	inOrder(root);cout << endl;




	return 0 ; 

}

	