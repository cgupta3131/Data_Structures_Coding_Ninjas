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


int tt = 0;

void DFS_Traversal(LinkedList *helper_array, int *colour, int *starting_time,
				   int *finishing_time, char *predeccesor, int V, 
				   int **edges_colour, char source_node)
{
	tt++;
	starting_time[source_node - 'a'] = tt;
	colour[source_node - 'a'] = 1; //Grey
	cout << source_node << " ";


	LinkedList *temp = helper_array[source_node - 'a'].head;

	while(temp != NULL)
	{
		if( colour[ (temp->data) - 'a' ]  == 0) //white colour
		{
			edges_colour[source_node - 'a'][temp->data - 'a'] = 'T'; //tree edge
			predeccesor[(temp->data) - 'a'] = source_node;
			DFS_Traversal(helper_array,colour,starting_time,finishing_time, 
			predeccesor, V, edges_colour,temp->data );
		}

		else if( colour[ (temp->data) - 'a' ]  == 1) //grey colour
		{
			edges_colour[source_node - 'a'][(temp->data) - 'a'] = 'B'; //back edge
		}


		else if( colour[ (temp->data) - 'a' ]  == 2) //black colour	
		{
			if( starting_time[source_node-'a'] < starting_time[(temp->data)-'a'])
				edges_colour[source_node - 'a'][(temp->data) - 'a'] = 'F'; //forward edge
			
			else
				edges_colour[source_node - 'a'][(temp->data) - 'a'] = 'C'; // cross edge
		}



		temp = temp->next;
	}	

	

	colour[source_node - 'a'] = 2; //black
	tt++;
	finishing_time[source_node - 'a' ] = tt;
}




void DFS(LinkedList* helper_array, int V, int **edges_colour)
{
	int *colour = new int[V]; // 0 for white, 1 for grey and 2 for black
	int *starting_time = new int [V]; //discovery time
	int *finishing_time = new int [V]; //finishing time
	char *predeccesor =  new char[V];
	

	for(int i=0;i<V;i++)
	{
		colour[i] = 0; //initialize all colours as white //Not Visited yet
		starting_time[i] = -1;
		finishing_time[i] = -1;
		predeccesor[i] = '\0';

	}
	for(int i=0;i<V;i++)
		if(colour[i] == 0)
	DFS_Traversal(helper_array,colour,starting_time,finishing_time,
		predeccesor,V,edges_colour,'a' + i);
}


bool isCyclic(int V, int **edges_colour)
{
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			if (edges_colour[i][j] == 'B')
				return true;

	return false;
}


int main()
{
	int V = 9;
	LinkedList *helper_array = new LinkedList[V];

	for(int i=0;i<V;i++)
	{
		helper_array[i].next = NULL;
		helper_array[i].head = NULL;
		helper_array[i].tail = NULL;
	}

    addEdge(helper_array, 'a', 'b');
    addEdge(helper_array, 'b', 'c');
    addEdge(helper_array, 'b', 'd');
    addEdge(helper_array, 'a', 'e');
    addEdge(helper_array, 'e', 'f');
    addEdge(helper_array, 'g', 'h');
    addEdge(helper_array, 'g', 'i');
    addEdge(helper_array, 'd', 'a');


    int **edges_colour = new int*[V];

	for(int i=0;i<V;i++)
	{
		edges_colour[i] = new int[V];
		for(int j=0;j<V;j++)
			edges_colour[i][j] = 0;
	}

    //printGraph(helper_array,V);
   	DFS(helper_array,V,edges_colour);
   	cout << endl;

   	if( isCyclic(V,edges_colour) ) 
   		cout << "Yes a Cyclic Exists " << endl;
   	else
   		cout << "No, there is No cyclic in the Graph" << endl;



	return 0 ; 

}

