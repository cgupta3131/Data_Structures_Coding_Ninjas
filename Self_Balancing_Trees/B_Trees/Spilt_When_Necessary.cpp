//It will split only if it is necessary that is it will first go to the Leaf Node 
//where we want to insert the element, if that Node is full, then it will split
//it and push the median upwards. (Bottom-Up Approach)

#include<bits/stdc++.h>

using namespace std;

class Node{

public:
	int *keys; //Array of keys
	int t; //Minimum Order -> Defines the range for number of keys
	Node **child; //Array of Child Pointers
	int n; //Number of keys present in the Node;
	bool isLeaf; 
	Node* parent;

	Node(int t, bool isLeaf, Node* parent)
	{
		this->t = t;
		this->isLeaf = isLeaf;
		this->parent = parent;

		keys = new int[2*t-1]; //as Maximum number of keys could be 2t-1;
		child = new Node* [2*t]; //as Maximum number of children could be 2t;
		n = 0; //Inital Number of keys present in the Node is Zero
	}


	Node *LeafNode(int k)
	{
		if(isLeaf == true)
			return this;

		int i=0;
		while(i<n && k > keys[i])
			i++;

		return child[i]->LeafNode(k);
	}

	//Will be called only when the Node is not Full and is a Leaf Node
	void InsertLeafNode(int k)
	{
		int i = n-1;

		while(i>=0 && keys[i] > k)
		{
			keys[i+1] = keys[i];
			i--;
		}

		keys[i+1] = k;
		n++;
	}

};


class BTree
{

public:
	Node *root;
	int t;

	BTree(int t)
	{
		this->t = t;
		root=NULL;
	}

	void InsertNode(int k)
	{
		//If Tree is Empty!
		if(root == NULL)
		{	
			root = new Node(t,true,NULL);
			root->keys[0] = k;
			root->n = 1;

			return;
		}

		else
		{
			Node *node = root->LeafNode(k);
			Node *node1 = NULL;
			Node *node2 = NULL;

			while(1)
			{

				if( node->n != (2*t-1) ) //If the Node is not full!
				{	
					/*  if(node1 != NULL)
					{
						int i;
						for(i=0;i<=node->n;i++)
						{
							if(node->child[i]->keys[0] == node1->keys[0])
								break;
						}

						for (int j = node->n; j >= i+1; j--)
							node->child[j+1] = node->child[j];

						node->child[i] = node1;
						node->child[i+1] = node2;	

						for(int j=node->n;j>i;j--)
							node->keys[j+1] = node->keys[j];

						node->keys[i] = k;
						node->n += 1;
					}

					else  */
					node->InsertLeafNode(k);
					return;
				}

				node1 = node;
				node2 = new Node(node->t,node->isLeaf,node->parent);

				node1->n = t-1;
				node2->n = t-1;

				for(int j=0;j<t-1;j++)
					node2->keys[j] = node->keys[j+t];

			/*  	if(node->isLeaf == false)
					for(int j=0;j<t;j++)
						node2->child[j] = node->child[j+t];  */

				int temp = node->keys[t-1];
				if(k > temp)
				{
					node2->InsertLeafNode(k);
					if(node2->isLeaf == false)
					{
						for(int j=0;j<=t;j++)
							node2->child[j] = node->child[j+t];
						for(int j=0;j<t;j++)
							node1->child[j] = node->child[j];
					}
				}
				else
				{
					node1->InsertLeafNode(k);
					if(node1->isLeaf == false)
					{
						for(int j=0;j<t;j++)
							node2->child[j] = node->child[j+t+1];
						for(int j=0;j<=t;j++)
							node1->child[j] = node->child[j];
					}
				}
				
				int i;
				Node *myParent = node->parent;

				if(myParent != NULL)
				{	
					for(i=0;i<=myParent->n;i++)
					{
						if(myParent->child[i]->keys[0] == node1->keys[0])
							break;
					}

					for (int j = myParent->n; j >= i+1; j--)
						myParent->child[j+1] = myParent->child[j];

					myParent->child[i] = node1;
					myParent->child[i+1] = node2;	

					/*  for(int j=myParent->n;j>i;j--)
						myParent->keys[j+1] = myParent->keys[j];

					myParent->keys[i] = k;
					myParent->n += 1;  */
				}

				k=temp;

				if(node->parent == NULL)
				{
					Node *s = new Node(t,false,NULL);
					s->child[0] = node1;
					s->child[1] = node2;

					node1->parent = s;
					node2->parent = s;

					s->keys[0] = temp;
					s->n += 1;
					root = s;

					return;
				}

				else
					node = node->parent;
			}
		}
	}
};


int main()
{
	BTree t(2);
	t.InsertNode(2);	
	t.InsertNode(6);
	t.InsertNode(7);
	t.InsertNode(3);
	t.InsertNode(4);
	t.InsertNode(12);
	t.InsertNode(14);
	t.InsertNode(8);
	t.InsertNode(10);
	t.InsertNode(20);
	t.InsertNode(21);
	t.InsertNode(15);
	t.InsertNode(18);
	t.InsertNode(23);
	t.InsertNode(25);

	cout << "CONCERNED POINTS" << endl;

	t.InsertNode(13);

	cout << t.root->child[1]->child[0]->n << endl;
	cout << t.root->child[1]->child[0]->keys[0] << endl;
	cout << t.root->child[1]->child[0]->keys[1] << endl;
	cout << t.root->child[1]->child[0]->keys[2] << endl << endl;

	cout << t.root->child[1]->child[1]->n << endl;
	cout << t.root->child[1]->child[1]->keys[0] << endl;
	cout << t.root->child[1]->child[1]->keys[1] << endl;
	cout << t.root->child[1]->child[1]->keys[2] << endl << endl;

	cout << t.root->child[1]->child[2]->n << endl;
	cout << t.root->child[1]->child[2]->keys[0] << endl;
	cout << t.root->child[1]->child[2]->keys[1] << endl;
	cout << t.root->child[1]->child[2]->keys[2] << endl << endl;

	
	
	return 0 ; 

}

