#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;
	

void kSortedArray(int input[], int n, int k)
{
	priority_queue<int> pq;

	for(int i=0;i<k;i++)
		pq.push(input[i]);

	int j=0;

	for(int i=k;i<n;i++)	
	{
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}


	while(pq.empty() == false)
	{
		input[j] = pq.top();
		pq.pop();
		j++;
	}


}

int main()
{
	int input[] = {10,22,6,7,9};
	int n = sizeof(input)/sizeof(input[0]);
	int k =3;
	kSortedArray(input,n,k);

	for(int i=0;i<n;i++)
		cout << input[i] << " ";
	cout << endl;



}