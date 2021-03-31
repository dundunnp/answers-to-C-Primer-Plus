#include <cmath>
#include "c11_2.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

double Vector::magval() const 
{ 
	return sqrt(x * x + y * y); 
}

double Vector::angval() const 
{ 
	if (x == 0.0 && y == 0.0)
		return 0.0;
	else
		return atan2(y, x);
}

Vector::Vector()
{
	x = y = 0.0;
	mode = RECT;
}

Vector::Vector(double n1, double n2, Mode form)
{
	mode = form;
	if (form == RECT)
	{
		x = n1;
		y = n2;
	}
	else if (form == POL)
	{
		x = n1 * cos(n2);
		y = n1 * sin(n2);
	}
	else
	{
		cout << "Incorrect 3rd argument to Vector() -- ";
		cout << "vector set to 0\n";
		x = y = 0.0;
		mode = RECT;
	}
}

void Vector::reset(double n1, double n2, Mode form)
{
	mode = form;
	if (form == RECT)
	{
		x = n1;
		y = n2;
	}
	else if (form == POL)
	{
		x = n1 * cos(n2);
		y = n1 * sin(n2);
	}
	else
	{
		cout << "Incorrect 3rd argument to Vector() -- ";
		cout << "vector set to 0\n";
		x = y = 0.0;
		mode = RECT;
	}
}

void Vector::polar_mode()
{
	mode = POL;
}

void Vector::rect_mode()
{
	mode = RECT;
}

Vector Vector::operator+(const Vector& b) const
{
	return Vector(x + b.x, y + b.y);
}

Vector Vector::operator-(const Vector& b) const
{
	return Vector(x - b.x, y - b.y);
}

Vector Vector::operator-() const
{
	return Vector(-x, -y);
}

Vector Vector::operator*(double n) const
{
	return Vector(x * n, y * n);
}

Vector operator*(double n, const Vector& a)
{
	return a * n;
}

std::ostream& operator<< (std::ostream& os, const Vector& v)
{
	if (v.mode == Vector::RECT)
		os << "(x, y) = (" << v.x << ", " << v.y << ")";
	else if (v.mode == Vector::POL)
		os << "(m, a) = (" << v.magval() << ", " << v.angval() << ")";
	else
		os << "Vector object mode is invalid";
	return os;
}