#include<iostream>
#include<string>
#include<string>
#include<queue>

using namespace std;

void helper_function(int **edges, int n, int starting_vertex, int *visited)
{

	queue<int> pendingVertices;

	pendingVertices.push(starting_vertex);
	visited[starting_vertex] = 1;

	while(pendingVertices.empty() ==  false)
	{
		int front = pendingVertices.front();
		pendingVertices.pop();

		for(int i=0;i<n;i++)
		{	
			if(edges[front][i] == 1 && visited[i] == false)
			{
				visited[i] = 1;
				pendingVertices.push(i);	
			}
			
		}
		
	}
}


bool isConnected(int **edges,int n,int *visited)
{	
	helper_function(edges,n,0,visited);

	for(int i=0;i<n;i++)
		if(visited[i] == 0)
			return false;

	return true;

}


int main()
{
	int n; //number ofvertices
	int e; //number of edges

	cin >> n >> e;

	int **edges = new int*[n];

	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
			edges[i][j] = 0;
	}

	for(int i=0;i<e;i++)	
	{
		int first, second;
		cin >> first >> second;
		edges[first][second] = 1;
		edges[second][first] = 1;
	}

	int *visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;

	if( isConnected(edges,n,visited)  == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0 ; 
}