#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;


vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    	
	int k = input.size(); //number of total sorted arrays!
	vector<int> output;

	int size1 = input[0]->size();
	priority_queue<int, vector<int>, greater<int> > p; //Min hea

	for(int i=0;i<size1;i++)
		p.push( ( *input[0] )[i] );


	for(int i=1;i<k;i++)
	{
		int size = input[i]->size();
		for(int j=0;j<size;j++)
			p.push( ( *input[i] )[j] );
	}


	while(!p.empty())
	{
		output.push_back(p.top() );
		p.pop();
	}


	return output;
}
