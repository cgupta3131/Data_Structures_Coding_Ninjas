#include <vector>
#include <climits>
#include <queue> //priority queue is included in this
#include <iostream>

using namespace std;

int kthLargest (vector<int> input, int n, int k)
{
	
	vector<int> output;
	priority_queue<int, vector<int>, greater<int> > p;

	for(int i=0;i<k;i++)
		p.push(input[i]);

	for(int i=k;i<n;i++)
	{
		if(p.top() < input[i])
		{
			p.pop();
			p.push(input[i]);
		} 
	}

	return p.top();
	   
}

int main()
{
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(6);
	arr.push_back(10);
	arr.push_back(11);
	arr.push_back(13);
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(20);
	int n = arr.size();
	int k = 4;

	cout << kthLargest(arr,n,k) << endl;


}
