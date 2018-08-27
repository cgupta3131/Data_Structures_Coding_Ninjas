#include <vector>
#include <climits>
#include <iostream>

using namespace std;

//This can also be taken as Heap Sort!! with Time Complexity as nlogn

class PriorityQueue{

	vector<int> pq;

public:
	PriorityQueue()
	{


	}

	bool isEmpty()
	{
		return pq.size() == 0;

	}

	int getSize()
	{
		return pq.size();
	}

	int getMax()
	{
		if(isEmpty() == true)
			return 0; //PriorityQueue is Empty!
		return pq[0];
	}

	void Insert(int element)
	{
		pq.push_back(element);

		int childIndex = pq.size()-1;
		int parentIndex = (childIndex-1)/2;

		while(childIndex != 0 || pq[parentIndex] > pq[childIndex] )
		{
			
			if(pq[childIndex] > pq[parentIndex])
			{
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;

			}

			childIndex = parentIndex;
			parentIndex = (childIndex-1)/2;

		}
	}

	int removeMax() 
	{
        
        int ans = pq[0];
        pq[0] = pq[pq.size()-1] ;
        pq.pop_back();

        int parentIndex = 0;
        int LeftChildIndex = 2*parentIndex + 1;
        int RightChildIndex = 2*parentIndex + 2;
        int maxIndex;
        int flag = 0;


        while(1)
        {

        	int maxValue = max( pq[parentIndex], max(pq[LeftChildIndex] , pq[RightChildIndex]) );

        	if(maxValue == pq[parentIndex])
        		break;

        	if(maxValue == pq[LeftChildIndex])
        	{	
        		maxIndex = LeftChildIndex;
        		int temp = pq[parentIndex];
        		pq[parentIndex] = pq[LeftChildIndex];
        		pq[LeftChildIndex] = temp;
        	}


        	else if(maxValue == pq[RightChildIndex])
        	{	
        		maxIndex = RightChildIndex;
        		int temp = pq[parentIndex];
        		pq[parentIndex] = pq[RightChildIndex];
        		pq[RightChildIndex] = temp;
        	}

        	if(flag == 1)
        		break;

        	parentIndex = maxValueIndex;
        	LeftChildIndex = 2*parentIndex + 1;
        	RightChildIndex = 2*parentIndex + 2;

        	if(LeftChildIndex >= pq.size() )
        		break;
        	

        	if(RightChildIndex >= pq.size() )
        	{
        		pq[RightChildIndex] = INT_MAX;
        		flag = 1;
        	}

        	
        	
        }

        return ans;
        
    }

};


int main()
{
	PriorityQueue p;

	p.Insert(100);
	p.Insert(10);
	p.Insert(15);
	p.Insert(4);
	p.Insert(17);
	p.Insert(21);
	p.Insert(67);

	cout << p.getSize() << endl;
	cout << p.getMin() << endl;

	while(p.isEmpty() == false)
		cout << p.removeMin() << " ";
	cout << endl << endl;

}