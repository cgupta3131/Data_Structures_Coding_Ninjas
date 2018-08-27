#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Node{

public:
	int data;
	Node *next;

};



/*
void Print(Node **arr, int mod)
{
	for(int i=0;i<mod;i++)
	{
		if(arr[i] == NULL)
			cout << i << " : " << endl;

		else
		{
			cout << i << " : ";

			while(arr[i] != NULL)
			{
				cout << arr[i] -> data << ", ";
				arr[i] = arr[i]->next;

			}

		}


	}

}
*/


Node *Insert(int x, Node *arr)
{

	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;

	if(arr[x].data == -1 )
		arr[x].data = x;

	else
	{
		while(arr[x].next != NULL)
			arr[x] = arr[x].next;

		arr[x].next = newNode;
	}

	return arr;



}
int main()
{
	int a[] = {15, 11, 27, 8, 12};
 	int n = sizeof(a)/sizeof(a[0]);

 	int mod = 7;

 	for(int i=0;i<n;i++)
 		a[i] = a[i] % 7;

 	Node arr[n];

 	for(int i=0;i<mod;i++)
 	{
 		arr[i].data = -1;
 		arr[i].next = NULL;
 	}

 	for(int i=0;i<n;i++)
 		arr = Insert(a[i],arr);


}