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


int indexOfNIter(Node *head, int n)
{
	Node *temp = head;

	if(head == NULL)
		return -1;
	int count = 0;

	while(temp != NULL)
	{
		if(temp->data == n)
		{
			return count;
		}

		count++;
		temp = temp->next;
	}

	return 0;
}


Node* append_LL(Node *head, int n)
{
	Node *temp = head;
	int total = 0;

	if(n==0)
		return head;

	while(temp != NULL)
	{
		total++;
		temp = temp->next;
	}

	int i = total - n;
	temp = head;

	Node *temp1 = head;
	for(int j=0;j<i-1;j++)
	{
		temp1 = temp1 -> next;
	}


	head = temp1->next;
	temp1->next = NULL;

	Node *temp2 = head;

	while(temp2->next != NULL)
	{
		temp2 = temp2->next;
	}

	temp2->next = temp;

	return head;


}

void print_reverse(Node *head)
{
	if(head == NULL)
		return;

	print_reverse(head->next);
	cout << head->data << " ";

}

Node *reverseLL(Node *head)
{

	Node *current,*prev,*forward;
	current = head;
	prev = NULL;

	while(current != NULL)
	{
		forward = current->next;
		current->next = prev;

		prev = current;
		current = forward;
	}
	
	head = prev;
	return head;
}


bool check_palindrome(Node* head)
{
	Node *temp = head;
	int total = 0;

	while(temp != NULL)
	{
		total++;
		temp = temp->next;
	}	

	
 	int mid = total/2;
	temp = head;

	for(int i=0;i<mid-1;i++)
		temp = temp->next;

	Node *head2 = temp->next;
	temp->next = NULL;
	head2 = reverseLL(head2);

	while(1)
	{
		if(head->data != head2->data)
			return false;
		
		head = head->next;
		head2 = head2->next;

		if(head == NULL)
			break;
		if(head2 == NULL)
			break;
	}

	return true;

}

bool checkPalindromeRec(Node *head)
{

	if(head == NULL || head->next == NULL)
		return true;

	Node *tail = head;
	Node *temp = tail;

	while(tail->next != NULL)
	{

		if(tail->next->next != NULL)
			temp = temp->next;

		tail = tail->next;
	}


	if(head->data == tail->data)
	{
		temp->next == NULL;
		checkPalindromeRec(head->next);
	}

	else
		return false;

}


Node *remove_Duplicate(Node *head)
{
	
	if(head == NULL || head->next == NULL)
		return head;

	Node *current = head->next;
	Node *prev = head;

	while(current != NULL)
	{
		if(prev->data == current->data)
		{
			Node *temp = current;	
			prev->next = current->next;
			current = current->next;
			delete temp;

			continue;
		}

		prev = current;
		current = current->next;
	}

	/*prev->next = current;*/

	return head;
}


int main()
{

	Node *head = takeInput();
	print(head);
	cout << endl;

	Node *head2 = remove_Duplicate(head);
	print(head2);


}