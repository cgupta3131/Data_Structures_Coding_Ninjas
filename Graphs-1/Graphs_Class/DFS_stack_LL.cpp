#include<bits/stdc++.h>

using namespace std;

class LinkedList{

public:

	char data;
	LinkedList *next;
	LinkedList *head;
	LinkedList *tail;
};

void addEdge(LinkedList *helper_array, char u, char v)
{
	LinkedList *node = new LinkedList;
	node->data = v;
	node->next = NULL;

	if(helper_array[u - 'q'].head == NULL)
	{
		helper_array[u - 'q'].head = node;
		helper_array[u - 'q'].tail = node;
	}
	

	else
	{
		helper_array[u -'q'].tail->next = node;	
		helper_array[u -'q'].tail = node;
	}

}


void printGraph(LinkedList *helper_array, int V)
{

	for(int i=0;i<V;i++)
	{
		cout << "Adjaceny List for vertex " << char(i + 'q') << " is " << endl;
		LinkedList *temp = helper_array[i].head;

		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl << endl;


	}

}

void DFS_Stack(LinkedList *helper_array, int V, bool *visited, char source, vector<char> *output)
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

		LinkedList *temp = helper_array[top - 'q'].head;

		while(temp != NULL)
		{
			if(visited[ (temp->data) - 'q'  ] ==  false)
				s.push(temp->data);
			temp = temp->next;
		}

	}
}


void Assign_Size(LinkedList *helper_array, int V, int *size)
{
	for(int i=0;i<V;i++)
    {
    	LinkedList *temp = helper_array[i].head;
    	int x = 0;
   		while(temp != NULL)
    	{
    		x++;
    		temp = temp->next;
   		}

   		size[i] = x;
   		delete temp;

    }
}


int main()
{
	int V = 10;
	int E = 14;
	LinkedList *helper_array = new LinkedList[V];

	for(int i=0;i<V;i++)
	{
		helper_array[i].next = NULL;
		helper_array[i].head = NULL;
		helper_array[i].tail = NULL;
	}

	for(int i=0;i<E;i++)
    {
    	char x, y;
    	cin >> x >> y;
    	addEdge(helper_array,x,y);
    }

    //printGraph(helper_array,V);

    int *size = new int[V];
    Assign_Size(helper_array, V ,size);

    bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	vector<char> output;

	for(int i=0;i<V;i++)
	{
		if(visited[i] == false)
			DFS_Stack(helper_array,V,visited, i+'q', &output);
	}

	cout << output.size() << endl;

	for(int i=1;i<output.size();i++)
	{
		char present = output[i];
		int x = i-1;

		while(x != -1)
		{	
			int flag = 0;

			LinkedList *temp = helper_array[ output[x] - 'q'].head;

			while(temp != NULL)
			{
				if(temp->data == present)
				{
					cout << "(" << output[x] << "," << present  << "),";
					flag = 1;
					break;	
				}

				temp = temp->next;
			}	

			if(flag == 1)
				break;
			
			else
				x--;
		}

	}


	return 0 ; 

}

