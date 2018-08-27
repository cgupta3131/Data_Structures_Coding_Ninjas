#include<iostream>
#include<string>
#include<vector>

using namespace std;


int Max(int A[], int i, int l, int r, int HEAP_SIZE) 
{
	int largestIndex = i;

	if(l<HEAP_SIZE && A[largestIndex] < A[l])
		largestIndex = l;

	if(r<HEAP_SIZE && A[largestIndex] < A[r])
		largestIndex = r;

	return largestIndex;
}

void Max_Heapify(int A[], int i, int HEAP_SIZE)
{
	int l = 2*i+1;
	int r = 2*i+2;

	int x = Max(A,i,l,r,HEAP_SIZE);
	if(x != i)
	{
		swap(A[x],A[i]);
		Max_Heapify(A,x,HEAP_SIZE);
	}
}

	

int main()
{
	int A[] = {4,1,3,2,16,9,10,14,8,7};
	int n = sizeof(A)/sizeof(A[0]); 	

	for(int i=(n-2)/2;i>=0;i--)	// from n/2 to n-1, there are leaf nodes present!
		Max_Heapify(A,i,n);
	
	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;
}
