#include<bits/stdc++.h>

using namespace std;

class LinkedList{

public:

	char data;
	LinkedList *next;
	LinkedList *head;
	LinkedList *tail;
};

void addEdge(LinkedList *helper_array, char u, char v)
{
	LinkedList *node = new LinkedList;
	node->data = v;
	node->next = NULL;

	if(helper_array[u - 'a'].head == NULL)
	{
		helper_array[u - 'a'].head = node;
		helper_array[u - 'a'].tail = node;
	}
	

	else
	{
		helper_array[u -'a'].tail->next = node;	
		helper_array[u -'a'].tail = node;
	}
}


void printGraph(LinkedList *helper_array, int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << char(i + 'a') << " is " << endl;
		LinkedList *temp = helper_array[i].head;

		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl << endl;


	}

}

void Assign_Size(LinkedList *helper_array, int V, int *size)
{
	for(int i=0;i<V;i++)
    {
    	LinkedList *temp = helper_array[i].head;
    	int x = 0;
   		while(temp != NULL)
    	{
    		x++;
    		temp = temp->next;
   		}

   		size[i] = x;
   		delete temp;

    }
}


bool isPath(LinkedList *helper_array, int V,char v1, char v2)
{
	queue<char> pendingVertices;

	bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    	visited[i] = false;

	pendingVertices.push(v1);
	visited[v1-'q'] = true;

	while(pendingVertices.empty() == false)
	{	
		char front = pendingVertices.front();

		if(front == v2)
			return true;

		pendingVertices.pop();

		LinkedList *temp = helper_array[front - 'q'].head;

		while(temp != NULL)
		{	
			if(    visited[ (temp->data) - 'q'] == false   )
			{
				visited[ (temp->data) - 'q'] = true;
				pendingVertices.push( temp->data );
			}

			temp = temp->next;
		}
	}

	return false;
}


int main()
{
	
	int V = 10;
	int E = 14;

	LinkedList *helper_array = new LinkedList[V];

	for(int i=0;i<E;i++)
    {
    	char x, y;
    	cin >> x >> y;
    	addEdge(helper_array,x,y);
    }

    int *size = new int[V];
    Assign_Size(helper_array, V ,size);

    //printGraph(helper_array,V);

    for(int i=0;i<10;i++)
    {
    	char first, second;
    	cout << "Enter starting vertex and ending vertex" << endl;
    	cin >> first >> second;
   		cout << isPath(helper_array,V,first,second) << endl;
    }

	return 0 ; 

}

