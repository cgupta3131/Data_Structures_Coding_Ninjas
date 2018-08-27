#include <vector>
#include <climits>
#include <iostream>

using namespace std;


int min(int a, int b)
{
	if(a>b)
		return b;
	else
		return a;

}


void inplaceHeapSort(int input[], int n)
{


	for(int i=1;i<n;i++) //equivalent to adding elements to Heap
	{
		int childIndex = i;
		int parentIndex = (childIndex-1)/2;

		while(childIndex != 0 || input[parentIndex] < input[childIndex] )
		{
			if(input[parentIndex] > input[childIndex] )
			{
				int temp = input[parentIndex];
				input[parentIndex] = input[childIndex];
				input[childIndex] = temp;
			}

			childIndex = parentIndex;
			parentIndex = (childIndex-1)/2;

		}	
	}


	int lastElementIndex = n-1;
	for(int i=0;i<n-1;i++)
	{
		int temp = input[lastElementIndex];
		input[lastElementIndex] = input[0];
		input[0] = temp;


		lastElementIndex--;

		int size = lastElementIndex+1;
		int parentIndex = 0;
		int LeftChildIndex = 2*parentIndex+1;
		int RightChildIndex = 2*parentIndex+2;
		int minIndex;
        int flag = 0;
        int flag2 = 0;


        while(1)
        {
        	if(LeftChildIndex >= size )
        		break;

        	if(RightChildIndex >= size )
        	{
        		int minValue = min(input[parentIndex],input[LeftChildIndex]);

        		if(minValue == input[LeftChildIndex])
        		{
        			int temp = input[parentIndex];
        			input[parentIndex] = input[LeftChildIndex];
        			input[LeftChildIndex] = temp;
        		}

        		break;
        	}

        	int minValue = min( input[parentIndex], min( input[LeftChildIndex] , input[RightChildIndex]) );

        	if(minValue == input[parentIndex])
        		break;

        	if(minValue == input[LeftChildIndex])
        	{	
        		minIndex = LeftChildIndex;
        		int temp = input[parentIndex];
        		input[parentIndex] = input[LeftChildIndex];
        		input[LeftChildIndex] = temp;
        	}


        	else if(minValue == input[RightChildIndex])
        	{	
        		minIndex = RightChildIndex;
        		int temp = input[parentIndex];
        		input[parentIndex] = input[RightChildIndex];
        		input[RightChildIndex] = temp;
        	}

        	if(flag == 1)
        		break;

        	parentIndex = minIndex;
        	LeftChildIndex = 2*parentIndex + 1;
        	RightChildIndex = 2*parentIndex + 2;
        	
        	
        }	
      

	}
	
 
}

int main()
{
	int input[] = {34,15,12,45,67,100,32,15};
	int n = sizeof(input)/sizeof(input[0]);

	inplaceHeapSort(input,n);

}
