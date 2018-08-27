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

	Fraction()
	{

	}

	Fraction(int numerator, int denominator )
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}	

	int getNumerator() const
	{
		return numerator;
	}

	int getDenominator() const
	{
		return denominator;
	}

	void setNumerator(int n)
	{
		numerator = n;
	}

	void setDenominator(int d)
	{
		denominator = d;
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
	Fraction f2(15,4);

	Fraction const f3;

	cout << f3.getNumerator() << " " << f3.getDenominator() << endl; 
	// the above line also gives error as through constant objects we can only access constant fucntions
	// hence we have to make numerator() and denominator() functions as constant


	
}
