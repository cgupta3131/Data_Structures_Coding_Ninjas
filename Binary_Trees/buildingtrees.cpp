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

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int *inorder, int PreS, int PreE , int InS, int InE)
{

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[PreS]);
	int length = PreE-PreS+1;
	if(length <= 0)
		return NULL;
	int i;
	for(i=0;i<length;i++)
	{
		if(inorder[i+InS] == preorder[PreS])
			break;
	}

	int PreS_left = 1+PreS;
	int PreE_left = i+PreS;
	int InS_left = InS+0;
	int InE_left = i-1+InS;

	int PreS_right = i+1+PreS;
	int PreE_right = PreS;
	int InS_right = i+1+InS;
	int InE_right = length-1+InS;	

	root->left = buildTreeHelper(preorder,inorder,PreS_left,PreE_left,InS_left,InE_left);
	root->right = buildTreeHelper(preorder,inorder,PreS_right,PreE_right,InS_right,InE_right);

	return root;


}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) 
{ 	//builidng tree if preorder and inorder given

	return buildTreeHelper(preorder,inorder,0,preLength-1,0,preLength-1);
}



BinaryTreeNode<int>* buildTree2(int *preorder, int preLength, int *inorder, int inLength) 
{
	if(preLength <= 0)
		return NULL;

	int i;
	for(i=0;;i++)
	{
		if(inorder[i] == preorder[0])
			break;
	}

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[0]);

	root->left  = buildTree2(preorder+1,i,inorder,i);
	root->right = buildTree2(preorder+i+1,preLength-1-i,inorder+i+1,preLength-1-i);

	return root;

}


BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) 
{
	if(postLength<=0)
		return NULL;

	int i;
	for(i=0;;i++)
	{
		if(inorder[i] == postorder[postLength-1])
			break;
	}



	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength-1]);

	root->left  = getTreeFromPostorderAndInorder(postorder,i,inorder,i); 
	root->right = getTreeFromPostorderAndInorder(postorder+i,postLength-1-i,inorder+i+1,postLength-1-i);

	return root;
}

/*BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) 
{
  if (postLength<=0)
    return NULL;

	  int count =0;
	  while (inorder[count]!=postorder[postLength-1])
	    count++;

  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postLength-1]);
  
  root->left = getTreeFromPostorderAndInorder(postorder,count,inorder,count);
  root->right= getTreeFromPostorderAndInorder(postorder+count,postLength-count-1,inorder+count+1,postLength-count-1);
  return root;
}*/


//BinaryTreeNode<int> *root
int main()
{
/*	BinaryTreeNode<int> *root = takeInputLevelWise();*/

	int len = 8;
	int postorder[12] = {8 ,4 ,5 ,2 ,6 ,7 ,3 ,1};
	int inorder[12] = {4 ,8 ,2 ,5 ,1 ,6 ,3 ,7};
	BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(postorder,len,inorder,len);
	printTreeLevelWise(root);

	delete(root);

}