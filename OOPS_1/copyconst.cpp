#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;


class Student{

	int age;
	

public :
	char *name;

	Student(int age, char *name)
	{
		this->age = age;
		//SHALLOW Copy
		//this->name = name;

		//DEEP Copy
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);

	}

	//Copy Constructor
	Student(Student const &s) //here we can't write Student(Student s) as this would be Student s = s1
							  //(which itself works as copy const and hence infinte loop would go and on)
							  //(therefore we pass by reference using constant pointer)
	{
		this->age = s.age;

		//SHALLOW Copy(Inbuilt Copy Constructor )
		//this->name = s.name

		//DEEP Copy
		this->name = new char[strlen(s.name)+1];
		strcpy(this->name,s.name);
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

	Student s2(s1); //Inbuilt copyconstructor is Shallow copyconstructor

	s2.name[0] = 'x';

	s1.display();
	s2.display();

	name[3] = 'e';
	Student s2(25,name);
	s2.display();
	s1.display();

}
