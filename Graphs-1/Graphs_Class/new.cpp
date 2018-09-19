#include<iostream>
#include<queue>

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

	/*  LinkedList *node2 = new LinkedList;
	node2->data = u;
	node2->next = NULL;

	if(helper_array[v - 'a'].head == NULL)
	{
		helper_array[v - 'a'].head = node2;
		helper_array[v - 'a'].tail = node2;
	}

	else
	{
		helper_array[v -'a'].tail->next = node2;	
		helper_array[v -'a'].tail = node2;
	}  */

}


void BFS_Traversal(LinkedList *helper_array, int V, char source)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	queue<char> q;

	q.push(source);
	visited[source - 'a'] = true;

	while(q.empty() == false)
	{
		char front = q.front();
		cout << front << " ";
		q.pop();

		LinkedList *temp = helper_array[front - 'a'].head;

		while(temp != NULL)
		{
			if( visited[ (temp->data) - 'a' ] == false    )
			{
				visited[ (temp->data) - 'a' ] = true;
				q.push(temp->data);

			}

			temp = temp->next;
		}
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


int main()
{
	int V = 5;
	LinkedList *helper_array = new LinkedList[V];

	for(int i=0;i<V;i++)
	{
		helper_array[i].head = NULL;
		helper_array[i].next = NULL;
		helper_array[i].tail = NULL;
	}

	addEdge(helper_array, 'a', 'b');
    addEdge(helper_array, 'a', 'e');
    addEdge(helper_array, 'b', 'c');
    addEdge(helper_array, 'b', 'd');
    addEdge(helper_array, 'b', 'e');
    addEdge(helper_array, 'c', 'd');
    addEdge(helper_array, 'd', 'e');

    printGraph(helper_array,V);

    BFS_Traversal(helper_array,V, 'a');
    cout << endl;
}