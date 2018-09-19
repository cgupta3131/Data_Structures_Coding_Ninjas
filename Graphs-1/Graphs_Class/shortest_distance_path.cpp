#include<iostream>
#include<string>
#include<string>
#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<char> adj[], char u, char v)
{
	//undirected graph
	adj[u-'a'].push_back(v);
	adj[v-'a'].push_back(u);
}

void printGraph(vector<char> adj[], int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << char(i+'a') << " is " << endl;
		cout << "Head";

		for(int j=0;j<adj[i].size();j++)
			cout << " -> " <<  adj[i][j] ;
		cout << endl << endl;
	}
}

void BFS_traversal(vector<char> adj[], int V, char source_node, char *predeccesor)
{
	int *colour = new int[V]; // 0 for white, 1 for grey and 2 for black
	int *distance = new int [V]; //distance from the source

	for(int i=0;i<V;i++)
	{
		colour[i] = 0; //initialize all colours as white //Not Visited yet
		distance[i] = -1;
		predeccesor[i] = '\0';
	}

	queue<char> q;

	colour[source_node-'a'] = 1; //visited;
	distance[source_node - 'a'] = 0;
	predeccesor[source_node - 'a'] = '\0';

	q.push(source_node);


	while(q.empty() ==  false)
	{
		char front = q.front();
		q.pop();

		cout << front << " ";

		for(int i=0; i<adj[front-'a'].size(); i++)
		{
			if(colour[ adj[front-'a'][i] - 'a' ] == 0) // if the node has not been viisted
			{
				colour[ adj[front-'a'][i] - 'a' ] = 1;
				distance[ adj[front-'a'][i] - 'a' ] = distance[front - 'a'] + 1;
				predeccesor[ adj[front-'a'][i] - 'a' ] = front;
				q.push(  adj[front-'a'][i] );
			}
		}

		colour[front - 'a' ] = 2; //all the adjacent nodes has been visited;
	}

	cout << endl;
}

void shortest_path( char *predeccesor, char source, char point)
{

	if( point == source)
	{
		cout << source << " ";
		return;
	}

	shortest_path( predeccesor,source,predeccesor[point - 'a'] );
	cout << point << " ";

	return; 
}

int main()

{

	int V = 5; //no. of vertices
	vector<char> *adj = new vector<char>[V];
    addEdge(adj, 'a', 'b');
    addEdge(adj, 'a', 'e');
    addEdge(adj, 'b', 'c');
    addEdge(adj, 'b', 'd');
    addEdge(adj, 'b', 'e');
    addEdge(adj, 'c', 'd');
    addEdge(adj, 'd', 'e');
    printGraph(adj, V);

    char *predeccesor =  new char[V];
    BFS_traversal(adj, V, 'a',predeccesor);
    cout << endl << endl;

    for(int i=0;i<V;i++)
    {
    	cout << "Shortest Path from a to " << char(i + 'a') << " is : " ;	
    	shortest_path(predeccesor, 'a', i + 'a');
    	cout << endl;
    }


	return 0 ; 

}

