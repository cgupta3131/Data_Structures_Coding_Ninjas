#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;


class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		next = NULL;

	}	

};

void print(Node *head)
{
	Node* temp = head;

	while(temp != NULL)
	{
		cout << temp->data << " " ;
		temp = temp->next;
	}

	cout << endl;
}


Node* takeInput()
{
	int data;
	cin >> data;

	Node *head = NULL;
	Node *tail = NULL;

	while(data != -1)
	{
		Node *newNode = new Node(data);
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail-> next;
		}

		cin >> data;

	}

	return head;

}

int length(Node* head)
{
	if(head == NULL)
		return 0;
	int n = 0;

	Node *temp = head;
	while(temp != NULL)
	{
		temp = temp->next;
		n++;
	}

	return n;

}


Node* Reverse_Iteratively(Node **head, int length_LL)
{	
	Node *temp = *head;

	while(temp->next != NULL)
		temp = temp->next;
	Node* tail = temp;

	Node *temp_head = tail;
	Node *current = tail;

	for(int i=length_LL-2;i>=0;i--)
	{
		Node *temp2 = *head;

		for(int j=0;j<i;j++)
			temp2 = temp2->next;

		current->next = temp2;
		temp2->next = NULL;

		current = temp2;
	}

	return temp_head;
}


void reverseRecursively(Node *head)
{
	Node *top = head;
	Node *rest = head->next;

	if(rest == NULL) //base case
	{
		cout << top->data << " ";
		return;
	}

	reverseRecursively(rest);

	rest->next = top;
	top->next = NULL;
	cout << top->data << " ";
}

Node *reverseLinkedList(Node *head) //Without Extra Space and in O(n) time
{

	Node *current = head;
    Node *Next = NULL;
    Node *prev = NULL;

    //Reversing the Linked List
    while(current != NULL)
    {
    	Next = current->next;
    	current->next = prev;
    	prev = current;
    	current = Next;
    }

    return prev;
}

Node *ModifyFirstHalfContents(Node *A)
{
	int count = 0;
    Node* temp = A;

    while(temp != NULL)
    {
    	count++;
    	temp = temp->next;
    }

    if(count == 0 || count == 1)
    	return A;

    if(count == 2)
    {
    	temp = A->next;
    	A->data = (temp->data) - (A->data);
    	return A;
    }

    temp = A;
    Node *prev = NULL;
    for(int i=0;i<count/2;i++)
    {
    	prev = temp;
    	temp = temp->next;
    }

    Node *temp_last = prev;
    prev->next = NULL;
    //Now A points to first half and temp points to second Half
    //Now I need to reverse the second half LL

    Node *current = temp;
    Node *Next = NULL;
    prev = NULL;

    //Reversing the Linked List
    while(current != NULL)
    {
    	Next = current->next;
    	current->next = prev;
    	prev = current;
    	current = Next;
    }

    Node *temp1 = A;
    Node *temp2 = prev;

    for(int i=0;i<count/2;i++)
    {
    	temp1->data = (temp2->data) - (temp1->data);
    	temp1 = temp1->next;
    	temp2 = temp2->next;
    }

    current = prev;
    Next = NULL;
    prev = NULL;

    //Reversing Back the list!
    while(current != NULL)
    {
    	Next = current->next;
    	current->next = prev;
    	prev = current;
    	current = Next;
    }
    //Now prev is the starting of the second half list

    temp_last->next = prev;
    return A;
}



int main()
{

	Node *head = takeInput();
	int length_LL = length(head); 
		
	head = ModifyFirstHalfContents(head);
	print(head);
	cout << endl << endl;

}