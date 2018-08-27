#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int highestFrequency(int *input, int n)
{

	unordered_map<int, int> m;

	for(int i=0;i<n;i++)
		m[input[i]]++;

	int max = input[0];

	for(int i=0;i<n;i++)
	{
		if(m[input[i]] > m[max])
			max = input[i];
	}

	return max;


}