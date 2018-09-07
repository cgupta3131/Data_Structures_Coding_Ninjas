#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS_Traversal(vector<int> adj[] , int V, int starting_index)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	queue<int> pendingVertices;

	pendingVertices.push(starting_index);
	visited[starting_index] = true;

	while(pendingVertices.empty() != true)
	{
		int front = pendingVertices.front();
		cout << front << " ";

		pendingVertices.pop();

	
		for(int i=0;i<adj[front].size();i++)
		{
			if(visited[ adj[front][i] ] == false)
			{
				
				visited[ adj[front][i] ] = true;
				pendingVertices.push(adj[front][i]);
			}

		}

	}

}



int main()
{
	int V = 5; //no. of vertices
	vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);	
    BFS_Traversal(adj,V,0);



	return 0 ; 

}

