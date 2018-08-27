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

int main()
{
	ifstream input;
	input.open("input.txt");
	int n;
	input >> n;

	int *arr = new int[20000];
	for(int i=0;i<n;i++)
		input >> arr[i];

	Top_Down_Build_Heap(arr,n);	


	for(int i=0;i<n;i++)
		cout << final[i] << " ";
	cout << endl;
}

