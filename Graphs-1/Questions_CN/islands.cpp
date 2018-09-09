#include<iostream>
#include<string>
#include<string>
#include<queue>

using namespace std;

void BFS_Traversal(int **edges, int n, int starting_vertex, int *visited)
{

	queue<int> pendingVertices;

	pendingVertices.push(starting_vertex);
	visited[starting_vertex-1] = 1;

	while(pendingVertices.empty() ==  false)
	{
		int front = pendingVertices.front();
		pendingVertices.pop();

		for(int i=0;i<n;i++)
		{	
			if(edges[front-1][i] == 1 && visited[i] == false)
			{
				visited[i] = 1;
				pendingVertices.push(i+1);	
			}
			
		}
		
	}
}


int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **edges = new int*[n];

	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
			edges[i][j] = 0;
	}

	for(int i=0;i<m;i++)	
	{
		int first, second;
		first = u[i];
		second = v[i];
		edges[first-1][second-1] = 1;
		edges[second-1][first-1] = 1;
	}

	int *visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;

	int x = 0;

	for(int i=0;i<n;i++)
	{
		if(visited[i] == 0)
		{
			x++;
			BFS_Traversal(edges,n,i+1,visited);
		}

	}

	return x;
  
}



int main()
{
	int n = 5; //number ofvertices
	int m = 3; //number of edges

	vector<int> u;
	u.push_back(1);
	u.push_back(2);
	u.push_back(3);

	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);

	cout << solve(n,m,u,v) << endl;

	

	return 0 ; 
}