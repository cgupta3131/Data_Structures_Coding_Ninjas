#include<bits/stdc++.h>

using namespace std;

class myStack{

	int data;
	myStack *next;
	myStack *head;

public:
	myStack()
	{
		data = -1;
		next = NULL;
		head = NULL;
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
	}	


	void Pop()
	{
		if(head == NULL)
		{
			cout << "Can't Pop as the Stack is already Empty" << endl;
			return;
		}

		myStack *temp = head;
		head = head->next;
		delete temp;
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

	void printStack()
	{

		if(head == NULL)
			return;

		myStack *temp =head;

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
	s.Push(5);
	s.Push(3);
	s.Push(2);
	s.printStack();
	s.Pop();
	s.printStack();

	return 0 ; 

}

