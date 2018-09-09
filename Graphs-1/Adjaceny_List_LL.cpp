#include<bits/stdc++.h>

using namespace std;

class LinkedList{

public:

	int data;
	LinkedList *next;
	LinkedList *head;
};

void addEdge(LinkedList *helper_array, int u, int v)
{
	LinkedList *node = new LinkedList;
	node->data = v;
	node->next = NULL;

	if(helper_array[u].head == NULL)
		helper_array[u].head = node;
	


	else
	{
		LinkedList *temp = helper_array[u].head;
		node->next = temp;
		helper_array[u].head = node;	
	}

	LinkedList *node2 = new LinkedList;
	node2->data = u;
	node2->next = NULL;

	if(helper_array[v].head == NULL)
		helper_array[v].head = node2;

	else
	{
		LinkedList *temp = helper_array[v].head;
		node2->next = temp;
		helper_array[v].head = node2;
		
	}
}


void printGraph(LinkedList *helper_array, int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << i << " is " << endl;
		LinkedList *temp = helper_array[i].head;

		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl << endl;


	}

}

int main()
{
	int V = 5;
	LinkedList *helper_array = new LinkedList[V];

	for(int i=0;i<V;i++)
	{
		helper_array[i].next = NULL;
		helper_array[i].head = NULL;
	}

	addEdge(helper_array, 0, 1);
    addEdge(helper_array, 0, 4);
    addEdge(helper_array, 1, 2);
    addEdge(helper_array, 1, 3);
    addEdge(helper_array, 1, 4);
    addEdge(helper_array, 2, 3);
    addEdge(helper_array, 3, 4);

   // cout << helper_array[0].head->next->data << endl;

    printGraph(helper_array,V);




	return 0 ; 

}

