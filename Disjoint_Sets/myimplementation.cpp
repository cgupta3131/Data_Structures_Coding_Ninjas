#include<bits/stdc++.h>

using namespace std;

class LL;

class Node{

public:
	int data;
	Node *next;
	LL *repPtr;
};


class LL{

public:
	Node *head;
	Node *tail;

};

class Collection{

public:
	unordered_map<int, Node*> NodeAddress;


	void Make(int a)
	{
		LL *myLinkedList = new LL;

		myLinkedList->head = new Node;

		myLinkedList->head->data = a;
		myLinkedList->head->next = NULL;
		myLinkedList->head->repPtr = myLinkedList;

		NodeAddress[a] = myLinkedList->head;
		myLinkedList->tail = myLinkedList->head;
	}


	LL *Find(int a)
	{
		Node *ptr = NodeAddress[a];
		return ptr->repPtr;
	}

	void Union(int a, int b)
	{
		LL *set1 = Find(a);
		LL *set2 = Find(b);

		Node *temp = set2->head;

		while(temp != NULL)
		{
			temp->repPtr = set1;
			temp = temp->next;
		}


		set1->tail->next = set2->head;
		set1->tail = set2->tail;

		delete set2;
	}

};



int main()
{

	Collection a;
	a.Make(13);
	a.Make(25);
	a.Make(35);
	a.Make(65);


	cout << a.Find(13) << endl;
	cout << a.Find(25) << endl;
	cout << a.Find(35) << endl;
	cout << a.Find(65) << endl;

	a.Union(25,35);
	cout << "Union of 25 and 35 done" << endl;

	cout << a.Find(13) << endl;
	cout << a.Find(25) << endl;
	cout << a.Find(35) << endl;
	cout << a.Find(65) << endl;


	a.Union(25,65);
	cout << "Union of 25 and 35 and 65 done" << endl;

	cout << a.Find(13) << endl;
	cout << a.Find(25) << endl;
	cout << a.Find(35) << endl;
	cout << a.Find(65) << endl;


	return 0 ; 

}

