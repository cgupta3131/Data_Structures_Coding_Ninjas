#include <vector>
#include <climits>
#include <queue> //priority queue is included in this
#include <iostream>

using namespace std;


int main()
{
	priority_queue<int> p; //default PQ class is Max Priority Class
	//empty() -> bool function
	//size() -> return int;
	//insert() -> return type void and inserts element according to Max PQ
	//top() -> returns the top most/root element and return type is int(T as priority_queue is a template)
	//pop() -> return type is VOID!! and max element is removed!

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



