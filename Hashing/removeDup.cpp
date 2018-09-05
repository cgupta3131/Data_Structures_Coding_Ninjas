#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<int> RemoveDuplicates(int *arr, int size)
{
	vector<int> output;
	unordered_map<int, bool> seen;

	for(int i=0;i< size ;i++)
	{	
		if(seen.count(arr[i]) > 0)
			continue;
		else
		{
			seen[arr[i]] = true;
			output.push_back(arr[i]);
		}

	}

	return output;

}

int main(){

int arr[] = {1,2,4,3,2,1,4,5};
vector<int> output = RemoveDuplicates(arr,8);


		
for(int i=0;i<output.size();i++)
	cout << output[i] << " ";

}