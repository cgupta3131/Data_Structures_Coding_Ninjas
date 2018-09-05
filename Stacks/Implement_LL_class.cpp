#include <stdio.h>
#include <iostream>

using namespace std;

class myStack{

public:
	int data;
	myStack *next;
	myStack *head;

	myStack()
	{	
		head = NULL;
		next = NULL;
	}

	void Push(int x)
	{
		if(head == NULL)
		{
			myStack *node = new myStack;
			node->data = x;
			node->next = NULL;
			head = node;
			return;
		}


		myStack *node = new myStack;
		node->data = x;
		node->next = head;

		head = node;

		return;

	}

	void Pop()
	{
		if(head == NULL)
		{
			cout << "Can't pop an element as stack is empty" << endl;
			return;
		}

		myStack *temp = head;
		head = head->next;
		delete(temp);

		return;
	}


	bool isEmpty()
	{
		if(head == NULL)
			return true;
		else
			return false;
	}


	myStack* TopElement()
	{
		return head;
	}


	void PrintStack()
	{	
		if(head == NULL)
			return;


		myStack *temp = head;


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
	myStack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	s.PrintStack();
	s.Pop();
	s.Pop();
	
	s.PrintStack();


	




}
