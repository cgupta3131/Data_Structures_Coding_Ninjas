#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
	Node *parent;
	int key;
	int degree;
	Node *leftMostChild;
	Node *RightSibling;

	Node()
	{
		parent = NULL;
		key = -1;
		degree = 0;
		leftMostChild = NULL;
		RightSibling = NULL;
	}
};

Node* findMin(Node *rootHead)
{
	Node *temp1 = rootHead;
	Node *min_Node = NULL;
	int min = INT_MAX;

	while(temp1 != NULL)
	{
		if(temp1->key < min)
		{
			min = temp1->key;
			min_Node = temp1;
		}

		temp1 = temp1->RightSibling;

	}

	return min_Node;
}


Node *Merge(Node *roothead1, Node *roothead2)
{
	Node *temp1 = roothead1;
	Node *temp2 = roothead2;

	Node *temp = new Node;
	if( temp1->degree <= temp2->degree )
	{
		temp = temp1;
		temp1 = temp->RightSibling;
	}

	else
	{
		temp = temp2;
		temp2 = temp2->RightSibling;
	}

	Node *temphead = temp;

	while(temp1 != NULL && temp2 != NULL) //loop will go on till both are not NULL
	{
		if( temp1->degree <= temp2->degree )
		{
			temp->RightSibling = temp1;
			temp = temp->RightSibling;
			temp1 = temp1->RightSibling;
		}

		else
		{
			temp->RightSibling = temp2;
			temp = temp->RightSibling;
			temp2 = temp2->RightSibling;
		}

	}

	if(temp1 != NULL)
	{
		while(temp1 != NULL)
		{
			temp->RightSibling = temp1;
			temp = temp->RightSibling;
			temp1 = temp1->RightSibling;
		}
	}

	else if(temp2 != NULL)
	{
		while(temp2 != NULL)
		{
			temp = temp2;
			temp = temp->RightSibling;
			temp2 = temp2->RightSibling;
		}
	}

	return temphead;

}


Node *link(Node *root1, Node *root2) //same sized Binomial Heaps!
{
	if(root1->key > root2->key)
	{
		root1->parent = root2;
		root1->RightSibling = root2->leftMostChild;
		root2->leftMostChild = root1;
		(root2->degree)++;

		return root2;
	}

	else
	{	
		root2->parent = root1;
		root2->RightSibling = root1->leftMostChild;
		root1->leftMostChild = root2;
		(root1->degree)++;

		return root1;
	}
}


Node* Union(Node *roothead1, Node *roothead2)
{

	Node *head_Merged_Heaps = Merge(roothead1,roothead2);

	Node *prev = NULL;
	Node *current = head_Merged_Heaps;
	Node *next = current->RightSibling;
	Node *next_to_next = next->RightSibling;

	

	while(next_to_next != NULL)
	{
		if( current->degree != next->degree   )
		{
			next_to_next = next_to_next->RightSibling;
			next = next->RightSibling;
			current = current->RightSibling;
			prev = current;
			continue;
		}

		if(current->degree == next->degree && next->degree == next_to_next->degree)
		{
			next_to_next = next_to_next->RightSibling;
			next = next->RightSibling;
			current = current->RightSibling;
			prev = current;
			continue;
		}

		if(current->degree == next->degree && next->degree != next_to_next->degree)
		{

			if(prev == NULL)
			{
				next_to_next = next_to_next->RightSibling;
				Node *temp1 = next;
				Node *temp2 = head_Merged_Heaps;
	
				Node *added = link(head_Merged_Heaps,next);
				next = temp1->RightSibling;
				added->RightSibling = next;
				head_Merged_Heaps = added;
				current = head_Merged_Heaps;

				cout << current->key << endl;
				cout << next->key << endl;
				cout << next_to_next->key << endl;

				delete temp1;
				delete temp2;

				continue;
			}

			if(prev != NULL)
			{
				next_to_next = next_to_next->RightSibling;
				Node *temp1 = next;
				Node *temp2 = current;

				Node *added = link(current,next);
				next = temp1->RightSibling;
				current = added;
				current->RightSibling = next;
				prev->RightSibling = current;
			}

		}		
	}

	if(current->degree == next->degree)
	{
		Node *temp1 = next;
		Node *temp2 = current;

		Node *added = link(current,next);
		next = temp1->RightSibling;
		current = added;
		current->RightSibling = next;
		prev->RightSibling = current;

	}

	return head_Merged_Heaps;
}

Node *Insert(Node *roothead, int x)
{
	Node *newNode;
	newNode->parent = NULL;
	newNode->key = x;
	newNode->degree = 0;
	newNode->leftMostChild = NULL;
	newNode->RightSibling = NULL;

	return Union(roothead, newNode);
}

Node *createHeap1()
{
	Node *a = new Node; 
	Node *b = new Node; 
	Node *c = new Node; 
	Node *d = new Node; 
	Node *e = new Node; 
	Node *f = new Node; 
	Node *g = new Node; 

	a->key = 12;
	b->key = 7;
	c->key = 15;
	d->key = 25;
	e->key = 29;
	f->key = 33;
	g->key = 41;

	a->parent = NULL;
	b->parent = NULL;
	c->parent = NULL;
	d->parent = b;
	e->parent = c;
	f->parent = c;
	g->parent = e;

	a->degree = 0;
	b->degree = 1;
	c->degree = 2;
	d->degree = 0;
	e->degree = 1;
	f->degree = 0;
	g->degree = 0;

	a->leftMostChild = NULL;
	b->leftMostChild = d;
	c->leftMostChild = e;
	d->leftMostChild = NULL;
	e->leftMostChild = g;
	f->leftMostChild = NULL;
	g->leftMostChild = NULL;

	a->RightSibling = b;
	b->RightSibling = c;
	c->RightSibling = NULL;
	d->RightSibling = NULL;
	e->RightSibling = f;
	f->RightSibling = NULL;
	g->RightSibling = NULL;


	return a;

}


Node *createHeap2()
{
	Node *a = new Node; 
	Node *b = new Node; 
	Node *c = new Node; 

	a->key = 18;
	b->key = 3;
	c->key = 37;

	a->parent = NULL;
	b->parent = NULL;
	c->parent = b;

	a->degree = 0;
	b->degree = 1;
	c->degree = 0;
	
	a->leftMostChild = NULL;
	b->leftMostChild = c;
	c->leftMostChild = NULL;
	
	a->RightSibling = b;
	b->RightSibling = NULL;
	c->RightSibling = NULL;
	
	return a;

}




int main()
{

	//First Binomial Heap
	Node *roothead1 = createHeap1();
	cout << findMin(roothead1)->key << endl;

	Node *roothead2 = createHeap2();
	cout << findMin(roothead2)->key << endl;

	Node *union_Heap = Union(roothead1,roothead2);
	



	return 0 ; 

}

