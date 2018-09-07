#include<bits/stdc++.h>

using namespace std;

vector<int> helper(int **edges, int n, int starting_vertex, int *visited)
{
	vector<int> output;

	queue<int> pendingVertices;

	pendingVertices.push(starting_vertex);
	visited[starting_vertex] = 1;

	while(pendingVertices.empty() ==  false)
	{
		int front = pendingVertices.front();
		pendingVertices.pop();

		output.push_back(front);

		for(int i=0;i<n;i++)
		{	
			if(edges[front][i] == 1 && visited[i] == false)
			{
				visited[i] = 1;
				pendingVertices.push(i);	
			}
			
		}
		
	}

	return output;
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


	vector< vector<int> > final;

	for(int i=0;i<n;i++)
	{
		if(visited[i] == 0) //for non-connected graphs
			final.push_back( helper(edges,n,i,visited) );
	}



	for(int i=0; i<final.size(); i++)
	{
		for(int j=0;j<final[i].size();j++)
		{
			sort(final[i].begin() , final[i].end()); // for increasing order
			cout << final[i][j] << " ";
		}
		cout << endl;

	}

	return 0 ; 
}