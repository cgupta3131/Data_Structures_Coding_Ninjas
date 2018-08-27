#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;


class ComplexNumbers{

private :
	int real;
	int imaginary;

public :
	 
	 ComplexNumbers(int real, int imaginary)
	 {
	 	this->real = real;
	 	this->imaginary = imaginary;
	 }

	 void print()
	 {
	 	cout << real << " + i" << imaginary << endl; 
	 }

	 void plus(ComplexNumbers const &c2)
	 {
	 	real = real + c2.real;
	 	imaginary = imaginary + c2.imaginary;

	 }

	 void multiply(ComplexNumbers const &c2)
	 {
	 	int temp_real = real; 
    	real = real*c2.real - imaginary*c2.imaginary;
    	imaginary = temp_real*c2.imaginary + imaginary*c2.real;
	 }

};


int main()
{
	ComplexNumbers c1(3,5);
	ComplexNumbers c2(4,1);

	c1.print();
	c2.print();

	c1.plus(c2);

	c1.print();
	c2.print();

}
