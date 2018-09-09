#include<bits/stdc++.h>

using namespace std;

// Kosaraju’s algorithm.


class LinkedList{

public:

	int data;
	LinkedList *next;
	LinkedList *head;
	LinkedList *tail;
};

void addEdge(LinkedList *helper_array, int u, int v)
{
	LinkedList *node = new LinkedList;
	node->data = v;
	node->next = NULL;

	if(helper_array[u].head == NULL)
	{
		helper_array[u].head = node;
		helper_array[u].tail = node;
	}
	
	else
	{
		helper_array[u].tail->next = node;	
		helper_array[u].tail = node;
	}

}


void printGraph(LinkedList *helper_array, int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << i  << " is " << endl;
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

stack<int> s;

void DFS_Traversal(LinkedList *helper_array, int V, bool *visited, int source)
{
	visited[source] = true;
	
	
	LinkedList *temp = helper_array[source].head;

	while(temp != NULL)
	{
		if(visited[temp->data] == false)
		{
			DFS_Traversal(helper_array,V,visited,temp->data);
		}

		temp = temp->next;
	}

	s.push(source);
	cout << source << " ";
}


void DFS_Utility(LinkedList *transpose, int V, bool *visited, int source)
{
	visited[source] = true;
	cout << source << " ";
	LinkedList *temp = transpose[source].head;

	while(temp != NULL)
	{

		if(visited[temp->data] == false)
		{
			//cout << temp->data << endl;
			DFS_Utility(transpose,V,visited,temp->data);
		}

		temp = temp->next;
	}
}

int main()
{
	int V = 12;
	int E = 17;
	LinkedList *helper_array = new LinkedList[V];

	for(int i=0;i<V;i++)
	{
		helper_array[i].next = NULL;
		helper_array[i].head = NULL;
		helper_array[i].tail = NULL;
	}

	LinkedList *transpose = new LinkedList[V];
    for(int i=0;i<V;i++)
	{
		transpose[i].next = NULL;
		transpose[i].head = NULL;
		transpose[i].tail = NULL;
	}

    for(int i=0;i<E;i++)
    {
    	int first, second;
    	cin >> first >> second;
    	addEdge(helper_array, first, second);
    	addEdge(transpose, second, first);
    }

    int *size = new int[V];
    Assign_Size(helper_array, V ,size);

    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    	visited[i] = false;

    for(int i=0;i<V;i++)
    	if(visited[i] == false)
    		DFS_Traversal(helper_array,V, visited,0);
    cout << endl << endl;

    for(int i=0;i<V;i++)
    	visited[i] = false;

    int x = 0;

    while(s.empty() == false)
    {
    	int top = s.top();
    	s.pop();

    	if(visited[top] == false)
    	{
    		DFS_Utility(transpose, V, visited, top);
    		cout << endl;

    	}
    }






	return 0 ; 

}

