#include<iostream>
#include<string>
#include<string>
#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<char> adj[], char u, char v)
{
	adj[u-'a'].push_back(v);
	adj[v-'a'].push_back(u);
}

void printGraph(vector<char> adj[], int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << char(i + 'a') << " is " << endl;
		cout << "Head";

		for(int j=0;j<adj[i].size();j++)
			cout << " -> " <<  adj[i][j] ;
		cout << endl << endl;
	}
}

int tt = 0;


void DFS_Traversal(vector<char> *adj, int *colour, int *starting_time,
				   int *finishing_time, char *predeccesor, int V, char source_node)
{
	tt++;
	starting_time[source_node - 'a'] = tt;
	colour[source_node - 'a'] = 1; //Grey
	cout << source_node << " ";

	for(int i=0; i<adj[source_node-'a'].size(); i++)
	{
		if(colour[ adj[source_node-'a'][i] - 'a' ] == 0)
		{
			predeccesor[source_node - 'a'] = source_node;
			DFS_Traversal(adj,colour,starting_time,finishing_time, 
				predeccesor, V, adj[source_node-'a'][i] );
		}

	}

	colour[source_node - 'a'] = 2;
	tt++;
	finishing_time[source_node - 'a' ] = tt;
}

void DFS(vector<char> adj[], int V)
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

	DFS_Traversal(adj,colour,starting_time,finishing_time,predeccesor,V,'a');
}


int main()

{

	int V = 5; //no. of vertices
	vector<char> *adj = new vector<char>[V];
    //addEdge(adj, 'a', 'b');
    addEdge(adj, 'a', 'e');
   	//addEdge(adj, 'b', 'c');
    addEdge(adj, 'b', 'd');
    addEdge(adj, 'b', 'e');
    addEdge(adj, 'c', 'd');
    addEdge(adj, 'd', 'e');
    printGraph(adj, V);


    DFS(adj, V);
    cout << endl << endl;

    return 0;	



	return 0 ; 

}

