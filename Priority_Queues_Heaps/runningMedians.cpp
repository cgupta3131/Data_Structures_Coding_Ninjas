#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

/*  https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/   */

/*We will create two heaps one Min and Max heap, Min heap will store all the elements which are greater than the recoreded median
and Max heap will store all the elements smaller than the recorded median so that Min heap root node can give me element just
greater than median and Max heap root node can give me element just smaller.

SAME SIZE ::
Now if size of two heaps are same, then if value to be inserted let it be 'a' is smaller than recored previous median 'm'
then we will push that element a in Max heap i.e elements less than recorded previous median and return new median as the top 
element of Max heap, and if 'a' is greater than 'm' , we will push it into Min heap and return new median as the top element of 
Min Heap

DIFFERENT SIZE ::
Now lets assusme that size of Max heap is greater than Min heap(always will be greater than max 1), therefore the previous
recored median is the top element of Max heap, as there are odd elements and Max heap are containing greater elements.

Now if 'a' is less than 'm' ,  then we know that we have to push 'a' to Max heap, but before pushing we will pop the top 
element of Max heap and push it into Min Heap, where this element will definately become the root/top element of the Min heap
and then we will push 'a' in Max heap and then median will be calculated as mean of top element of Max heap and top element of Min
heap.*/


void findMedian(int input[], int n){ //time limit will exceed for bigger arrays
    	
    priority_queue<int> p;	//Max Heap will store the numbers smaller than median recorded;
    priority_queue<int, vector<int>, greater<int> > q; //Min Heap will store the numbers larger than the median recored

    int median = 0;

   	for(int i=0;i<n;i++)
   	{
   		int size1 = p.size();
   		int size2 = q.size();

  
   		if(size1 == size2)
   		{
   			
   			if(input[i] < median)
   			{
   				p.push(input[i]);
   				median = p.top();
   			}	

   			else
   			{
   				q.push(input[i]);
   				median = q.top();
   			}
   		}


   		else if(size1 > size2)
   		{
   		
   			if(input[i] < median)
   			{
   				int temp = p.top();
   				p.pop();
   				q.push(temp);
   				p.push(input[i]);
   			}

   			else
   				q.push(input[i]);	

   			median = ( p.top() + q.top() )/ 2;   					
   		}

   		else
   		{	
   			if(input[i] > median)
   			{
   				int temp = q.top();
   				q.pop();
   				p.push(temp);
   				q.push(input[i]);
   			}

   			else
   				p.push(input[i]);

   			median = ( p.top() + q.top() )/ 2;
   		}

   		cout << median << endl;	
   	}
    
}

int main()
{
	int arr[] = {6,2,1,3,7,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	findMedian(arr,n);


}
