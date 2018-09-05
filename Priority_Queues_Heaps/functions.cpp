#include<iostream>
#include<string>
#include<vector>

using namespace std;



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


//MOVE UP
void move_up(int A[], int index, int &HEAP_SIZE)
{


	while(index>=0 && A[index] > A[parent(index)])
	{
		if(index == 0)
			break;
		swap(A[index],A[parent(index)]);
		index = parent(index);
	}
}






void Heap_Insert(int A[], int element, int &HEAP_SIZE)
{
	A[HEAP_SIZE] = element;
	int i = HEAP_SIZE;

	HEAP_SIZE++;

	move_up(A,i,HEAP_SIZE);

	
}


//DELETE
void Heap_Delete(int A[], int index, int &HEAP_SIZE)
{
	A[index] = A[HEAP_SIZE-1];
	HEAP_SIZE--;

	if(A[index] > A[parent(index)])
		move_up(A,index,HEAP_SIZE);

	else
		move_down(A,index,HEAP_SIZE);
}

int Heap_Extract_Max(int A[], int &HEAP_SIZE)
{
	int answer = A[0];

	swap(A[0],A[HEAP_SIZE-1]);
	HEAP_SIZE--;

	move_down(A,0,HEAP_SIZE);

	return answer;

}


void Heap_Increase_Key(int A[], int index, int x, int &HEAP_SIZE)
{
	if(x < A[index])
		cout << "The value can't be increased" << endl;

	else
	{
		A[index] = x;
		move_up(A,index,HEAP_SIZE);

	}



}


void print(int A[], int HEAP_SIZE)
{
	for(int i=0;i<HEAP_SIZE;i++)
		cout << A[i] << " ";
	cout << endl;
}



int main()
{

	int A[100] = {1,2,3,4,5,6,7,8,9};
	int HEAP_SIZE = 0;

	for(int i=0;i<9;i++)
		Heap_Insert(A,A[i],HEAP_SIZE);
	

	print(A,HEAP_SIZE);
	cout << Heap_Extract_Max(A,HEAP_SIZE) << endl;
	print(A,HEAP_SIZE);

	
	


}

