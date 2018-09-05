#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;


class Student{

public:
	int age;
	int const rollnumber;
	int &x; //age reference variable -> therefore this has to be initialized while creation of memory just like const int!!!

	//If we have constant data types or reference variables in any class then they have to be initialized using Initialization List!!

	Student(int r,int age) : rollnumber(r) ,  age(age) , x(this->age) { 
	//Initializtion list for Constant arguements! and this line means : int const rollnumber = r;
	}


};


int main()
{
	Student s1(101,10);
	s1.age = 15;


}
