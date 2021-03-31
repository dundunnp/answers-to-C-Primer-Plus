#include "c11_7.h"

Complex::Complex()
{
	real = imag = 0.0;
}

Complex::Complex(double x, double y)
{
	real = x; imag = y;
}

Complex Complex::operator+(const Complex& c) const
{
	Complex sum;
	sum.real = real + c.real;
	sum.imag = imag + c.imag;
	return sum;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex diff;
	diff.real = real - c.real;
	diff.imag = imag - c.imag;
	return diff;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex mul;
	mul.real = real * c.real - imag * c.imag;
	mul.imag = real * c.imag + imag * c.real;
	return mul;
}

Complex Complex::operator*(double n) const
{
	Complex mul;
	mul.real = real * n;
	mul.imag = imag * n;
	return mul;
}

Complex Complex::operator~() const
{
	Complex conj;
	conj.real = real;
	conj.imag = -imag;
	return conj;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "(" << c.real << "," << c.imag << "i)\n";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
	std::cout << "real: ";
	if (!(is >> c.real))
		return is;
	std::cout << "imaginary: ";
	is >> c.imag;
	return is;
}