#include <vector>
#include <climits>
#include <queue> //priority queue is included in this
#include <iostream>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > p;  //great> means that we will swap only if parent is greater than child
														// default is smaller that is for Max Heap!

	p.push(100);
	p.push(21);
	p.push(7);
	p.push(165);
	p.push(78);
	p.push(4);


	cout << p.size() << endl;
	cout << p.empty() << endl;
	cout << p.top() << endl<<endl;

	while(p.empty() == false)
	{
		cout << p.top() << endl;
		p.pop();
	}



}
