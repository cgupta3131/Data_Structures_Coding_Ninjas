#include<iostream>
#include<string>
#include<string>
#include<queue>

using namespace std;

void print(int **edges, int n, int starting_vertex, int *visited)
{

	queue<int> pendingVertices;

	pendingVertices.push(starting_vertex);
	visited[starting_vertex] = 1;

	while(pendingVertices.empty() ==  false)
	{
		int front = pendingVertices.front();
		cout << front << " ";
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

	for(int i=0;i<n;i++)
	{
		if(visited[i] == 0) //for non-connected graphs
			print(edges,n,i,visited);
	}

	return 0 ; 
}