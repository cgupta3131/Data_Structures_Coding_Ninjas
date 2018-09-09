#include<iostream>
#include<string>
#include<string>
#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<char> adj[], char u, char v)
{
	adj[u-'q'].push_back(v);
}

void printGraph(vector<char> adj[], int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << char(i + 'q') << " is " << endl;
		cout << "Head";

		for(int j=0;j<adj[i].size();j++)
			cout << " -> " <<  adj[i][j] ;
		cout << endl << endl;
	}
}


bool isPath(vector<char> adj[], int V,char v1, char v2)
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

		for(int i=0;i<adj[front - 'q'].size() ; i++)
		{	
			if(visited[ adj[front - 'q'][i] - 'q' ] == false)
			{
				visited[ adj[front - 'q'][i] - 'q' ] = true;
				pendingVertices.push( adj[front - 'q'][i] );
			}

		}
	}

	return false;
}



int main()

{

    int V = 10; //no. of vertices
	int E = 14;
	vector<char> *adj = new vector<char>[10];

	for(int i=0;i<E;i++)
    {
    	char x, y;
    	cin >> x >> y;
    	addEdge(adj,x,y);
    }

    //printGraph(adj,V);

    for(int i=0;i<10;i++)
    {
    	char first, second;
    	cout << "Enter starting vertex and ending vertex" << endl;
    	cin >> first >> second;
   		cout << isPath(adj,V,first,second) << endl;
    }




	return 0 ; 

}

