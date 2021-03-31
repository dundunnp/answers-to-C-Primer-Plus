#pragma once
#ifndef C11_7_H_
#define C11_7_H_

#include <iostream>

class Complex
{
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double x, double y);

	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator*(double n) const;
	Complex operator~() const;

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);
	friend Complex operator*(double n, const Complex& c) { return c * n; }
};

#endif
