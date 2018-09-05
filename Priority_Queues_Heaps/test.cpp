#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

class myNode
{
public:
	int data;
	int flag;

	myNode(int data)
	{
		this->data = data;
		this->flag = 0;
	}
};

class compare{

public:
	int operator()(myNode* a, myNode *b)
	{
		if(a->data == b->data)
			return a->flag < b->flag;
		else
			return a->data < b->data;

	}


};


int main()
{
	priority_queue<myNode*, vector<myNode*> , compare  > p; //Max Heap


	myNode *a = new myNode(3);
	a->flag = 0;
	p.push(a);

	myNode *b = new myNode(3);
	b->flag = 1;
	p.push(b);

	myNode *c = new myNode(3);
	c->flag = 2;
	p.push(c);

	cout << p.top()->data << " ";
	cout << p.top()->flag << endl;
	p.pop();

	cout << p.top()->data << " " ;
	cout << p.top()->flag << endl;
	p.pop();

	cout << p.top()->data << " ";
	cout << p.top()->flag << endl;
	p.pop();

	
}