#include<bits/stdc++.h>

using namespace std;

class myQueue{

	int data;
	myQueue *next;
	myQueue *head;
	myQueue *tail;

public:
	myQueue()
	{
		next = NULL;
		head = NULL;
		tail = NULL;
	}


	void Push(int x)
	{
		if(tail == NULL)
		{
			myQueue *node = new myQueue;
			node->data = x;
			node->next = NULL;
			tail = node;
			head = node;

			return;
		}

		myQueue *node = new myQueue;
		node->data = x;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}

	void Pop()
	{
		if(head == NULL)
		{
			cout << "Can't Pop as the Queue is empty" << endl;
			return;
		}

		if(head->next == NULL)
		{
			myQueue *temp = head;
			head = NULL;
			tail = NULL;
			delete temp;

			return;
		}

		myQueue *temp = head;
		head = head->next;
		delete temp;
	}

	myQueue *front()
	{
		return head;
	}

	myQueue *back()
	{

		return tail;
	}

	int size()
	{
		if(head == NULL)
			return 0;

		myQueue *temp = head;
		int x = 0;

		while(temp != NULL)
		{	
			temp = temp->next;
			x++;
		}

		return x;
	}

	void PrintQueue()
	{
		if(head == NULL)
			return;

		myQueue *temp = head;

		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
		return;

	}






};



int main()
{
	myQueue q;
	q.Push(1);
	q.PrintQueue();
	q.Push(2);
	q.PrintQueue();
	q.Push(3);
	q.PrintQueue();
	q.Pop();
	q.PrintQueue();


	return 0 ; 

}

