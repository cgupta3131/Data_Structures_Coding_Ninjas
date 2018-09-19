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



int main()
{

	Node *head = takeInput();
	print(head);

	int length_LL = length(head); //returns the length of the Linked List formed!

	head = Reverse_Iteratively(&head,length_LL);
	cout << "The Reversed List is : ";
	print(head);	

	reverseRecursively(head);




}