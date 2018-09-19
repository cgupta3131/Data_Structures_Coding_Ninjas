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

void printIthNode(Node *head, int i) 
{
	if(head == NULL)
		return;

	Node *temp = head;
	for(int j=0;j<i;j++)
	{
		head = head->next;
		if(head == NULL)
			return;
	}

	cout << head->data << endl;
}


Node* Insert(Node *head, int i, int data)
{
	Node *temp = head;
	if(i==0)
	{
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;

		return head;
	}

	for(int j=0;j<i-1;j++)
	{
		temp = temp->next;
	}

	Node *temp2 = temp->next;

	Node *newNode = new Node(data);
	temp->next = newNode;
	newNode->next = temp2;

	return head;
	
}

Node* Delete(Node* head, int i)
{
	Node *temp = head;
	if(i==0)
	{
		head = temp->next;
		delete temp;

		return head;
	}

	for(int j=0;j<i-1;j++)
	{
		temp = temp->next;
	}

	Node *temp2 = temp->next; // temp2 is to be deleted one
	Node *temp3 = temp2->next;

	temp->next = temp3;
	delete temp2;

	return head;


}

Node* insertNodeRec(Node *head, int i, int data)
{
	if(head == NULL)
		return head;

	if(i==0)
	{
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;

		return head;
	}

	if(i==1)
	{
		Node *newNode = new Node(data);
		Node *temp2 = head->next;
		head->next = newNode;
		newNode->next =  temp2;

		return head;
	}



	else
	{
		Node *temp = insertNodeRec(head->next,i-1,data);
		
		return head;

	}

}

Node *deleteNodeRec(Node *head, int i)
{
	if(head == NULL)
		return head;

	if(i==0)
	{
		Node *temp = head;
		head = temp->next;
		delete temp;	

		return head;
	}


	if(i==1)
	{
		Node *temp1 = head->next;
		Node *temp2 = temp1->next;

		head->next = temp2;
		delete temp1;

		return head;
	}

	else
	{
		deleteNodeRec(head->next,i-1);

		return head;
	}




}

int main()
{

	Node *head = takeInput();
	print(head);
	cout << endl;


}