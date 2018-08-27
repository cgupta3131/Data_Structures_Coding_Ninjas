#include <vector>
#include <climits>
#include <queue> //priority queue is included in this
#include <iostream>

using namespace std;

bool checkMaxHeap(int arr[], int n){
   	

   for(int i=0;i<n;i++)
   {
   		int parentIndex = i;
   		int LeftChildIndex = 2*parentIndex + 1;
   		int RightChildIndex = 2*parentIndex + 2;

   		if(  LeftChildIndex < n && arr[parentIndex] < arr[LeftChildIndex]  )
   			return false;

   		if(  RightChildIndex < n && arr[parentIndex] < arr[RightChildIndex]  )
   			return false;
   }

   return true;
}
