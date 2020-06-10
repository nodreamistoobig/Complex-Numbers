#include <iostream>
#include <iomanip>
#include "Complex.h"

#define PI 3.14159265358979323846


using namespace std;

Complex::Complex(double r, double i)
{
	real = r;
	img = i;
}

Complex::Complex()
{
	real = 1;
	img = 1;
}


Complex& Complex::operator +=(const Complex& c)
{
	real = real + c.real;
	img = img + c.img;
	return *this;
}

Complex Complex::operator +(const Complex& c) const
{
	Complex res(*this);
	res += c;
	return res;
}


Complex Complex::operator -() const
{
	Complex c(-real, -img);
	return c;
}

Complex Complex::operator -(const Complex& c) const
{
	return (*this + (-c));
}

Complex& Complex::operator -=(const Complex& c)
{
	return (*this += (-c));
}

Complex Complex:: operator *(const Complex& c) const
{
	Complex res(*this);
	res.real = real * c.real - img * c.img;
	res.img = real * c.img + c.real * img;
	return res;
}

Complex& Complex::operator *=(const Complex& c)
{
	Complex res(*this);
	res = *this * c;
	real = res.real;
	img = res.img;
	return *this;
}

Complex Complex:: operator /(const Complex& c) const
{
	Complex res(*this);
	res.real = (real*c.real + img*c.img) / (c.real*c.real + c.img*c.img);
	res.img = (c.real*img + real*c.img) / (c.real*c.real + c.img*c.img);
	return res;
}

Complex& Complex::operator /=(const Complex& c)
{
	Complex res(*this);
	res = *this / c;
	real = res.real;
	img = res.img;
	return *this;
}

double Complex::Module() {
	return sqrt(real * real + img * img);
}

double Complex::Phase() {
	return 180 * atan(img / real) / PI;
}

Complex Complex::Power(int p){
	Complex res(*this);
	double m = this->Module();
	double f = this->Phase() * PI / 180;
	double mInPow=1;
	for (int i=0; i<p;i++){
		mInPow *= m;
	}
	cout << "m=" << mInPow<<" ";
	res.real = mInPow * cos(p * f);
	res.img = mInPow * sin(p * f);
	return res;
}

istream& operator >>(istream& in, Complex& c)
{
	in >> c.real >> c.img;
	return in;
}

ostream& operator <<(ostream& out, const Complex& c)
{
	if (c.real) 
		out << setprecision(3)<<c.real;
	if (c.img > 0) {
		cout << "+";
		if(c.img!=1)
			cout << setprecision(3) <<c.img;
		cout << "i";
	}
	else if (c.img < 0) {
		if (c.img != -1)
			cout << setprecision(3) << c.img<<"i";
		else
			cout << "-i";
	}
	return out;
}
