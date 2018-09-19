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

Node *takeInput()
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
			tail->next = head;
		}
		else
		{
			tail->next = newNode;
			tail = tail-> next;
			tail->next = head;
		}

		cin >> data;

	}

	return head;
}

void print(Node *head)
{
	if(head == NULL)
		return;

	cout << head->data << " ";

	Node *temp = head->next;

	while(temp != head )
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

}

int main()
{
	Node *head = takeInput();
	print(head);
	cout << endl;




}