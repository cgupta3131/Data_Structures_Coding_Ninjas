#include<iostream>
#include<string>
#include<vector>
#include<fstream>


using namespace std;
	
void Insert(int output[],int &HEAP_SIZE, int x)
{
	HEAP_SIZE++;
	output[HEAP_SIZE-1] = x;
	int i = HEAP_SIZE-1;


	while(i>=0 && output[i] > output[(i-1)/2]) //if child is greater than it's parent
	{	
		if( i == 0)
			break;
		swap(output[i], output[(i-1)/2]);
		i = (i-1)/2;

	}
}



int final[] = {};

void Top_Down_Build_Heap(int arr[], int size)
{
	
	int HEAP_SIZE = 0;

	for(int i=0;i<size;i++)
		Insert(final,HEAP_SIZE,arr[i]);
		

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

// MOVE DOWN
int Max(int A[], int i, int l, int r, int HEAP_SIZE) 
{
	int largestIndex = i;

	if(l<HEAP_SIZE && A[largestIndex] < A[l])
		largestIndex = l;

	if(r<HEAP_SIZE && A[largestIndex] < A[r])
		largestIndex = r;

	return largestIndex;
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

	int *arr = new int[n];
	for(int i=0;i<n;i++)
		input >> arr[i];

	Top_Down_Build_Heap(arr,n);	


	for(int i=0;i<n;i++)
		cout << final[i] << " ";
	cout << endl;

	int k;
	cin >> k;	

	for(int i=0;i<k;i++)
		cout << Heap_Extract_Max(final,n) << " ";
	cout << endl;

	clock_t stop = clock();
	cout << stop-start << endl;

}