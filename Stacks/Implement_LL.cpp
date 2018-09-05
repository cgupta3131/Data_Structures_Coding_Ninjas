#include <stdio.h>
#include <iostream>

using namespace std;

class LinkedList{

public:
	int data;
	LinkedList *next;
};



LinkedList* Push(LinkedList* head, int x)
{
	if(head == NULL)
	{
		LinkedList *node = new LinkedList;
		node->data = x;
		node->next = NULL;
		return node;
	}


	LinkedList *node = new LinkedList;
	node->data = x;
	node->next = head;

	head = node;

	return head;

}

LinkedList* Pop(LinkedList* head)
{
	if(head == NULL)
	{
		cout << "Can't pop an element as stack is empty" << endl;
		return NULL;
	}

	LinkedList *temp = head;
	head = head->next;
	delete(temp);

	return head;


}

bool isEmpty(LinkedList *head)
{
	if(head == NULL)
		return true;
	else
		return false;

}

LinkedList* TopElement(LinkedList *head)
{
	return head;
}

void PrintStack(LinkedList* head)
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

	LinkedList* head = NULL;
	head = Push(head,5);
	head = Push(head,6);
	head = Push(head,7);
	head = Push(head,8);
	head = Push(head,9);

	PrintStack(head);




}