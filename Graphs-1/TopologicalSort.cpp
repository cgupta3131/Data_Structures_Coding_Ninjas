#include<iostream>
#include<string>
#include<string>
#include<queue>
#include<stack>
//possible only for directed Acyclic Graph

using namespace std;

stack<int> s;


void helper(int **edges, int n, int vertex, bool *visited)
{
	visited[vertex] = true;

	for(int i=0;i<n;i++)
		if(edges[vertex][i] == 1 && visited[i] == false)
			helper(edges,n,i,visited);


	s.push(vertex);
}



void Topological_Sort(int **edges, int n)
{
	

	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;

	for(int i=0;i<n;i++)
		if(visited[i] == false)
			helper(edges, n, i,visited);

	cout << endl << "Topological Sort is : " ;	
	while(s.empty() == false)
	{	
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl << endl;
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
		edges[first][second] = 1; // directed graph
	}

	Topological_Sort(edges,n);




	return 0 ; 
}