#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;
	
vector<int> kSmallest(int *input, int n, int k) 
{
	vector<int> output;
	priority_queue<int> p;

	for(int i=0;i<k;i++)
		p.push(input[i]);

	for(int i=k;i<n;i++)
	{
		if(p.top() > input[i])
		{
			p.pop();
			p.push(input[i]);
		} 
	}

	while( !p.empty() )
	{
		output.push_back( p.top() );
		p.pop();
	}


	return output;
}


int main()
{
	int input[] = {10,22,6,7,9};
	int n = sizeof(input)/sizeof(input[0]);
	int k =2;
	
	vector<int> output = kSmallest(input,n,k);

	for(int i=0;i<output.size();i++)
		cout << output.at(i) << " ";
	cout << endl;


}