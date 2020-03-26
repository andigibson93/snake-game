class Rational
{
public:
	Rational();
    Rational(int, int);
        
    void setNumerator(int);
    int getNumerator();
    
    void setDenominator(int);
    int getDenominator();
    
    void add(Rational);
    void subtract(Rational);
    void multiply(Rational);
    void divide(Rational);
	
    void printRational();
    void printFloat();

private:

	int numerator;
	int denominator;
    
    int gcd(int, int);
    void reduce();
};


//Rational.cpp

#include<iostream>
#include "Rational.h"
using namespace std;

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;

    if(d == 0)
        cout << "Undefined" <<endl;
    else
        reduce();
}

void Rational::setNumerator (int n)
{
    numerator = n;
}

int Rational::getNumerator()
{
    return numerator;
}

void Rational::setDenominator(int d)
{
    denominator = d;
}

int Rational::getDenominator()
{
    return denominator;
}

void Rational::add(Rational other)
{
    // a/b + c/d == (a*d + c*b)/ b*d
    numerator = numerator * other.getDenominator() + other.getNumerator() * denominator;
    denominator *= other.getDenominator();
    reduce();
}

void Rational::subtract(Rational other)
{
    //a/b - c/d == a/b + (-c/d)
    Rational negated(other.getNumerator() * -1, other.getDenominator());
    add(negated);
}

void Rational::multiply(Rational other)
{
    numerator *= other.getNumerator();
    denominator *= other.getDenominator();
    reduce();
}

void Rational::divide(Rational other)
{
    //(a/b)/(c/d) == (a/b)*(d/c)
    Rational inverted(other.getDenominator(), other.getNumerator());
    multiply(inverted);
}

int Rational::gcd(int a, int b)
{
    if (b == 0) 
        return a; 
    return gcd(b, a % b);
}

void Rational::reduce()
{
    int divider = gcd(numerator, denominator);
    numerator /= divider;
    denominator /= divider;
}

void Rational::printRational()
{
    cout << numerator << "/" << denominator <<endl;
}

void Rational::printFloat()
{
    cout << numerator / static_cast <float> (denominator) <<endl;
}



#include<iostream>
#include "Rational.h"
using namespace std;
//RationalMain.cpp

int main()
{
	Rational r1(4,8);
	cout << "The fraction of 4/8 is reduced to ";
	r1.printRational();

	cout << "The fraction of 4/8 as float is: ";
	r1.printFloat();

	Rational r2(1,3);
	cout << "Adding 1/3 to 1/2 returns:  ";
	r1.add(r2);
	r1.printRational();
	cout << "The result as a float is: ";
	r1.printFloat();

	Rational r3(4,6);
	cout<< "Subtacting 4/6 from 1/2 returns: ";
	r1.subtract(r3);
	r1.printRational();
	cout<< "The result as a float is: ";
	r1.printFloat();

	Rational r4(1,5);
	Rational r5(10,1);
	cout << "Multiplying 1/5 by 10 returns ";
	r4.multiply(r5);
	r4.printRational();
	cout<< "The result as a float is: ";
	r4.printFloat();
    
    Rational r6(2,1);
    cout << "Dividing 2/1 by 2/1 returns: ";
    r6.divide(r6); //should return 1/1
    r6.printRational();
    cout<< "The result as a float is: ";
    r6.printFloat();

	return 0;

}
