#include<bits/stdc++.h>

using namespace std;

class node{

public:

	string data;
	int depth;

	node(string s, int d)
	{	
		data = s;
		depth = d;
	}


};

string ReverseString(string input, int start, int end)
{
	string output = "";
	int len = input.length();

	for(int i=end;i>=start;i--)
		output += input[i];

	for(int i=end+1;i<len;i++)
		output += input[i];

	return output;

}


int main()
{
	int n;
	cin >> n;

	string input = "";
	for(int i=0;i<n;i++)
	{
		char c;
		cin >> c;
		input += c;
	}

	string helper = "";
	for(int i=0;i<n;i++)
		helper += i+'1';

	map<string, int> my_map;

	queue<node> q;
	q.push( node(input,0) );
	my_map[input] = 1; //tells input has been visited

	while(1)
	{
		node currNode = q.front();
		q.pop(); 

		if(currNode.data == helper)
		{
			cout << currNode.depth << endl;
			return 0;
		}


		for(int i=1;i<n;i++)
		{
			string newString = ReverseString(currNode.data,0,i);
			if(my_map.find(newString) == my_map.end()) // that is we haven't found the String
			{
				my_map[newString] = 1;
				q.push(node(newString,currNode.depth+1));
			}

		}

	}

	
}
