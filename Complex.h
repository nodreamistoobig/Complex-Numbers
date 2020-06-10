#ifndef _COMPLEX_H
#define _COMPLEX_H

using namespace std;

class Complex
{
public:
	double real;	//real part
	double img;	//imaginary part
	Complex(double r, double i);
	Complex();
	
	Complex& operator +=(const Complex& c);
	Complex operator +(const Complex& c) const;

	Complex operator -() const;
	Complex operator -(const Complex& c) const;
	Complex& operator -=(const Complex& c);

	Complex operator *(const Complex& c) const;
	Complex& operator *=(const Complex& c);

	Complex operator /(const Complex& r) const;
	Complex& operator /=(const Complex& c);

	double Module();
	double Phase();
	Complex Power(int p);

	friend istream& operator >>(istream& in, Complex& r);
	friend ostream& operator <<(ostream& out, const Complex& r);
	
};

#endif 
