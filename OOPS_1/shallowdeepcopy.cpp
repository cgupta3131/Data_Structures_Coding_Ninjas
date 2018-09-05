#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;


class Student{

	int age;
	char *name;

public :
	Student(int age, char *name)
	{
		this->age = age;
		//SHALLOW Copy
		//this->name = name;

		//DEEP Copy
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);

	}

	void display()
	{
		cout << name << " " << age << endl;
	}

};


int main()
{
	char name[] = "abcd";
	Student s1(15,name);
	s1.display();

	name[3] = 'e';

	Student s2(25,name);
	s2.display();

	s1.display();

	/*With shallow copy, when we call s1.display() second time, then the name that will be printed would be "abce" and not "abcd"
	while with deep copy, when we call s1.display(), then the name will be printed "abcd".
	This is because in Deep Copy the whole original name is copied while in Shallow Copy only the address of the 0th index is copied
	and hence any chances in the array would also be shown in s1.
*/

}

