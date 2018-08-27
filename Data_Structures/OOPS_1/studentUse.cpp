#include <iostream>

using namespace std;



class Student
{

public :

int rollNumber;

private:

int age;

public:

//Default Constructor -> will help to initialize values when an object is called

Student(){

	cout << "Constructor 1 Called" << endl;	
}	


//Parametrized Constructor
Student(int roll){

	cout << "Constructor 2 Called" << endl;
	this->rollNumber = roll;	// this is a pointer which holds the address of the object that will be called
}

Student(int roll,int age){

	cout << "Constructor 3 Called" << endl;
	this-> rollNumber = roll; 
	this->age = age;	
}


~Student(){

cout << "Destructor Called" << endl;

}


void display()
	{

	cout << age << " " << rollNumber << endl;


	}
int getAge()
	{
	return age;
	}	


};	


int main()
{
	
	Student s1; 		// Constructor 1 called
	Student s2(101);	// Constructor 2 called
	Student s3(20,102); // Constructor 3 called

	Student s4(s3);  	// Copy Constructor  called

	s4.display();

	s1=s2; 				// Copy Assignment Operator
	s1.display();

	Student s5 = s4;    // Copy Constructor Called and Not Copy Assignmnet!




}
