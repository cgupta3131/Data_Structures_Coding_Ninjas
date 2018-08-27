#include<iostream>
#include<cstring>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

class Fraction{

private :

	int numerator;
	int denominator;

public :

	
	Fraction(int numerator, int denominator )
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}	


	void print()
	{
		cout << this->numerator << "/" << this->denominator << endl;

	}

	void add(Fraction const &f2)
	{
		int lcm  = this->denominator * f2.denominator; 
		int x  = lcm/denominator;
		int y = lcm/f2.denominator;

		int num = x*numerator + ( y *f2.numerator);

		numerator = num;
		denominator = lcm;	
	}

	void multiply(Fraction const &f2)
	{
		int num = numerator * f2.numerator;
		int den  = this->denominator * f2.denominator;

		numerator = num;
		denominator = den;


	}



};


int main()
{
	Fraction f1(10,2);
	Fraction f3(15,4);

	f1.print();
	f3.print();

	cout << endl;

	f1.add(f3);

	f1.print();
	f3.print();

	cout << endl;

	f1.multiply(f3);

	f1.print();
	f3.print();


}
