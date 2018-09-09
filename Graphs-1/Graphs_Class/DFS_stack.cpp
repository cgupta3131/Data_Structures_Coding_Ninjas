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

void DFS_Stack(vector<char> *adj, int V, bool *visited, char source, vector<char> *output)
{
	stack<char> s;
	s.push(source);


	while(s.empty() == false)
	{
		char top = s.top();
		s.pop();

		if(visited[top-'q'] == false)
		{
			output->push_back(top);
			visited[top - 'q'] = true;
		}


		for(int i=adj[top-'q'].size() - 1; i >=0 ; i--)
		{
			if(visited[ adj[top-'q'][i] - 'q'  ] ==  false)
				s.push( adj[top-'q'][i] );
		}

	}
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

    bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	vector<char> output;

	for(int i=0;i<V;i++)
	{
		if(visited[i] == false)
			DFS_Stack(adj,V,visited,i+'q',&output);
	} 	    	


	for(int i=1;i<output.size();i++)
	{
		char present = output[i];
		int x = i-1;

		while(x != -1)
		{	
			int flag = 0;
			for(int j=0; j< adj[ output[x] - 'q'  ].size() ; j++)
			{
				if( adj[ output[x] - 'q'  ][j] == present )
				{
					cout << "(" << output[x] << "," << present  << "),";
					flag = 1;
					break;
				}
			}

			if(flag == 1)
				break;
			
			else
				x--;
		}

	}



	return 0 ; 

}

