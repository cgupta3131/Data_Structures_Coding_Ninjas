#include<bits/stdc++.h>

using namespace std;

class Node{

public:
	int *keys; //Array of keys
	int t; //Minimum Order -> Defines the range for number of keys
	Node **child; //Array of Child Pointers
	int n; //Number of keys present in the Node;
	bool isLeaf; 

	Node(int t, bool isLeaf)
	{
		this->t = t;
		this->isLeaf = isLeaf;

		keys = new int[2*t-1]; //as Maximum number of keys could be 2t-1;
		child = new Node* [2*t]; //as Maximum number of children could be 2t;
		n = 0; //Inital Number of keys present in the Node is Zero
	}


	void NodeTraversal()
	{
		int i;
		for(i=0; i<n;i++)
		{
			if(isLeaf == false)
				child[i]->NodeTraversal();
			cout << " " << keys[i];	
		}

		//As number of Children are (n+1)
		//Hence we need one more Traversal!
		if(isLeaf == false)
			child[i]->NodeTraversal();
	}

	Node* NodeSearch(int k)
	{
		int i=0;
		while(i<n && k > keys[i])
			i++;

		if(keys[i] == k)
			return this;

		if(isLeaf == true)
			return NULL;

		return child[i]->NodeSearch(k);
	}

	//Will be always called when the Node is not full
	void InsertNonFull(int k)
	{
		//Initialize i with the rightMost element in the Node!
		int i = n-1;

		//If the Root itself is the leaf Node, then we just insert the key
		if(isLeaf == true) 
		{
			while(i>=0 && keys[i] > k)
			{
				//Shifting the keys to one place ahead, as we have to maintain Increasing order
				keys[i+1] = keys[i];
				i--;
			}

			//And then assigning the value of k
			keys[i+1] = k;
			n++;
		}


		else
		{
			//Find the Child which is going to have this new key
			while(i>=0 && keys[i] > k)
				i--;

			if(child[i+1]->n == 2*t-1)
			{	
				//Splitting the child!
				SplitChild(i+1,child[i+1]);

				//After the split, the middle key goes up and child[i+1] is splitted
				//into two parts, Now we have to check which one of those will have the 
				//new Key!
				if(keys[i+1] < k)
					i++;
			}
			child[i+1]->InsertNonFull(k);
		}
	}

	//To split the child y of this Node
	//Note that Y must be full when this function is called!
	void SplitChild(int i, Node *y)
	{
		//z will contain the last (t-1) keys
		Node *z = new Node(y->t,y->isLeaf);
		z->n = t-1;

		for(int j=0;j<t-1;j++)
			z->keys[j] = y->keys[j+t];

		//Copy the last t children of 'Y' to 'Z'
		if(y->isLeaf == false)
		{	
			for(int j=0;j<t;j++)
				z->child[j] = y->child[j+t];
		}

		//Reducing the Number of keys in y to (t-1)
		y->n = t-1;

		//Shifting all the childs to one place right as new Child(Z) is about to be added
		for (int j = n; j >= i+1; j--)
			child[j+1] = child[j];

		child[i+1] = z;

		//Middle key of 'Y' will move up to the Node! 
		//The Middle key of Y will be less than the all the keys of 'Z' that are to the 
		//right of i

		//Hence we will shift all those keys of 'Z' to right and then insert Middle Key of 'Y'
		//to its appropriate place!
		for (int j = n-1; j >= i; j--)
			keys[j+1] = keys[j];

		keys[i] = y->keys[t-1]; 

		n++;
	}
};


class BTree{

public:
	Node *root;
	int t;

	BTree(int t)
	{
		this->t = t;
		root=NULL;
	}

	void TreeTraversal()
	{
		if(root != NULL)
			root->NodeTraversal();
	}

	Node* TreeSearch(int k)
	{
		if(root!=NULL)
			root->NodeSearch(k);
		else
			return NULL;
	}

	void InsertNode(int k)
	{
		//If Tree is Empty!
		if(root == NULL)
		{	
			root = new Node(t,true);
			root->keys[0] = k;
			root->n = 1;

			return;
		}

		else
		{
			if( root->n != (2*t - 1) )
				root->InsertNonFull(k);

			else
			{
				//Allocate Memory for New Root!
				Node *s = new Node(t,false);

				s->child[0] = root;
				s->SplitChild(0,root);

				//New Root s has now two children, Now we have to decide which of 
				//these two children must contain the key

				int i=0;
				if (s->keys[0] < k) 
                	i++;
                s->child[i]->InsertNonFull(k);

                //Change the Root!
                root = s;
			}
		}
	}
};




int main()
{	
	BTree t(3);
	t.InsertNode(10);
	t.InsertNode(20);
	t.InsertNode(30);
	t.InsertNode(40);
	t.InsertNode(50);
	t.InsertNode(60);
	t.InsertNode(70);
	t.InsertNode(80);
	t.InsertNode(90);

	cout << "Traversal of Constructed Tree is : ";
	t.TreeTraversal();
	cout << endl;


	return 0 ; 

}

