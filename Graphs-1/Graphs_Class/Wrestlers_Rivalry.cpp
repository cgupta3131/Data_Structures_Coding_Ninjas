#include<iostream>
#include<string>
#include<string>
#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
	adj[u-1].push_back(v);
	adj[v-1].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << i+1 << " is " << endl;
		cout << "Head";

		for(int j=0;j<adj[i].size();j++)
			cout << " -> " <<  adj[i][j] ;
		cout << endl << endl;
	}
}

int main()

{

	int V; //no. of vertices
	int E;

	cin >> V >> E;
	vector<int> *adj = new vector<int>[V];
    for(int i=0;i<E;i++)
    {
    	int first,second;
    	cin >> first >> second;
    	addEdge(adj,first,second);
    }
    printGraph(adj, V);

    char *assign = new char[V];
    bool *visited = new bool[V];

    for(int i=0;i<V;i++)
    {
    	assign[i] = 'N';
    	visited[i] = false;
    }

    char current = 'B';
    char next = 'G';

    assign[0] = current;
    visited[0] = true;

    queue<int> q;
    q.push(1);


    int flag = 0;
    while(q.empty() == false)
    {
    	int front = q.front();
    	//visited[front - 1] = true;
    	q.pop();

    	current = assign[front - 1];
    	if(current == 'B')
    		next = 'G';
    	else
    		next = 'B';

    	for(int i=0;i<adj[front-1].size() ; i++)
    	{
    		if( visited[ adj[front-1][i] - 1] == false   )
    		{
    			visited[ adj[front-1][i] - 1 ] = true;
    			q.push(adj[front-1][i]);
    		}


			if(  assign[ adj[front-1][i] - 1 ] == 'N')
				assign[ adj[front-1][i] - 1 ] = next;
			else
			{	
				if( assign[ adj[front-1][i] - 1 ] == current  )
				{
					flag = 1;
					break;
				}
			}	
    	}

    	if(flag == 1)
    		break;
    }

    if(flag == 1)
    {
    	cout << "NOT POSSIBLE" << endl;
    	return 0;
    }


    vector<int> Good;
    vector<int> Bad;

    for(int i=0;i<V;i++)
    {
    	if(assign[i] == 'G')
    		Good.push_back(i+1);
    	else
    		Bad.push_back(i+1);
    }

    cout << "Good Guys : ";
    for(int i=0;i<Good.size();i++)
    	cout << Good[i] << " ";
    cout << endl;

    cout << "Bad Guys : ";
    for(int i=0;i<Bad.size();i++)
    	cout << Bad[i] << " ";
    cout << endl;


	return 0 ; 

}

