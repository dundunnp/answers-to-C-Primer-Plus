#include <iostream>
#include "c10_2.h"
#include <cstring>

Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, fn);
}

void Person::Show() const
{
	using std::cout;
	cout << fname << " " << lname << "\n";
}

void Person::FormalShow() const
{
	using std::cout;
	cout << lname << " " << fname << "\n";
}