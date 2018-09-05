#include <stdio.h>
#include <iostream>

using namespace std;

class LinkedList{

public:
	int data;
	LinkedList *next;
};

LinkedList *head = new LinkedList;

void createNode(int x)
{
	head->data = x;
	head->next = NULL;
}

void Push(int x)
{
	if(head == NULL)
	{
		head->data = x;
		head->next = NULL;
		return;
	}


	LinkedList *temp = new LinkedList;
	temp->data = x;
	temp->next = NULL;

	LinkedList *temp2 = head;

	while(temp2->next != NULL)
		temp2 = temp2->next;

	temp2->next = temp;


}

void Pop()
{
	if(head == NULL)
	{
		cout << "Can't pop an element as stack is empty" << endl;
		return;
	}

	LinkedList *temp = new LinkedList;
	temp = head;
	head = head->next;
	delete(temp);

}

void PrintStack()
{
	if(head == NULL)
		return;

	LinkedList *temp = head;

	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
	return;

	

}


int main()
{

	createNode(10);
	Push(11);

	Push(12);
	Push(13);
	Push(14);
	Pop();
	Pop();
	
	PrintStack();



}
