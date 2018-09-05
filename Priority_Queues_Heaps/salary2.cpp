#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ctime>

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




int parent(int i)
{
	return (i-1)/2;
}

int leftChild(int i)
{
	return 2*i+1;
}

int rightChild(int i)
{
	return 2*i+2;
}

void move_down(int A[], int index, int &HEAP_SIZE)
{
	int l = leftChild(index);
	int r = rightChild(index);

	int x = Max(A,index,l,r,HEAP_SIZE);
	if(x != index)
	{
		swap(A[x],A[index]);
		move_down(A,x,HEAP_SIZE);
	}	


}



int Heap_Extract_Max(int A[], int &HEAP_SIZE)
{
	int answer = A[0];

	swap(A[0],A[HEAP_SIZE-1]);
	HEAP_SIZE--;

	move_down(A,0,HEAP_SIZE);

	return answer;

}
	

int main()
{
	clock_t start = clock();

	ifstream input;
	input.open("input.txt");

	int n;
	input >> n;

	int *A = new int[n];
	for(int i=0;i<n;i++)
		input >> A[i];

	for(int i=(n-2)/2;i>=0;i--)	// from n/2 to n-1, there are leaf nodes present!
		Max_Heapify(A,i,n);
	
	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;


	int k;
	cin >> k;	

	for(int i=0;i<k;i++)
		cout << Heap_Extract_Max(A,n) << " ";
	cout << endl;


	clock_t stop = clock();
	cout << stop-start << endl;



}
