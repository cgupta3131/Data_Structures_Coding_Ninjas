#include<bits/stdc++.h>

using namespace std;

int arr[5] = {-1};

int front = -1;
int rear = -1;
int size = 5;

void enQueue(int x)
{
	if(front == -1 && rear == -1)
	{	
		front = rear = 0;
		arr[front] = x;
		arr[rear] = x;
		return;
	}

	if(rear != size-1)
	{
		rear++;
		arr[rear] = x;
		return;
	}

	if(rear == size-1)
	{
		rear = 0;
		arr[rear] =x;
		return;
	}
}

void deQueue()
{
	if(front == -1 && rear == -1)
	{
		cout << "Queue is already empty" << endl;
		return;
	}

	if(front != size - 1)
	{
		arr[front] = 0;
		front++;
		return;
	}

	else
	{
		arr[front] = 0;
		front = 0;
		return;
	}
}

void printQueue()
{
	for(int i=0;i<size;i++)
		cout << arr[i] << " ";
	cout << endl;
}



int main()
{
	enQueue(1);
	printQueue();	
	enQueue(2);
	printQueue();
	enQueue(3);
	printQueue();
	enQueue(4);
	printQueue();
	enQueue(5);
	printQueue();
	deQueue();
	printQueue();
	deQueue();
	printQueue();
	deQueue();
	printQueue();
	enQueue(6);
	printQueue();
	enQueue(7);
	printQueue();
	enQueue(8);
	printQueue();
	deQueue();
	printQueue();
	deQueue();
	printQueue();
	deQueue();
	printQueue();



	return 0 ; 

}

