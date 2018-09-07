#include<iostream>
#include<string>
#include<string>
#include<queue>
#include<vector>

using namespace std;


bool hasPath(int **edges, int n, int *visited, int v1, int v2)
{

	queue<int> pendingVertices;

	pendingVertices.push(v1);
	visited[v1] = 1;

	while(pendingVertices.empty() ==  false)
	{
		int front = pendingVertices.front();

		if(front == v2)
			return true;
		
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

	return false;
}


//hasPath(int **edges, int n, int *visited, int v1, int v2)

vector<int>* getPath2(int **edges, int n, int *visited, int v1, int v2)
{

	vector<int> *output = new vector<int>;
	output->push_back(v1);

	if(v1 == v2)
		return output;


	int *helper = new int[n];
	for(int i=0;i<n;i++)
		helper[i] = visited[i];

	helper[v1] = 1;
	visited[v1] = 1;

	int flag = 0;
	int children = -1;

	for(int i=0;i<n;i++)
	{
		if(i == v1)
			continue;

		if(edges[v1][i] == 1 && visited[i] == 0)
		{

			if(hasPath(edges,n,helper,i,v2) )
			{	
				flag = 1;
				children = i;
				break;
			}
		}
	}

	if(flag == 0)
		return NULL;

	vector<int> *helper_vector;
	helper_vector = getPath2(edges,n,visited,children,v2);

	for(int i=0;i<helper_vector->size();i++)
		output->push_back( helper_vector->at(i) );

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

	int v1, v2;

	cin >> v1 >> v2;

	int *visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;


	vector<int> *output = getPath2(edges,n,visited, v1,v2);

	if(output == NULL)
		return 0;

	int index = output->size();
	for(int i=0;i<output->size();i++)
		cout << output->at(index-1-i) << " ";
	cout << endl;

}

