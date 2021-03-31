#include "c13_2.h"
#include <cstring>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy_s(performers, strlen(s1) + 1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{	
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	using std::cout;
	using std::endl;
	if (performers == nullptr || label == nullptr)
		cout << "Error, empty Object." << endl;
	else 
	{
		cout << "performers:\t" << performers << endl;
		cout << "label:\t" << label << endl;
		cout << "selections:\t" << selections << endl;
		cout << "playtime:\t" << playtime << endl;
	}
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* nm, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	name = new char[strlen(nm) + 1];
	strcpy_s(name, strlen(nm) + 1, nm);
}

Classic::Classic(const Classic& cl) : Cd(cl)
{
	name = new char[strlen(cl.name) + 1];
	strcpy_s(name, strlen(cl.name) + 1, cl.name);
}

Classic::Classic() : Cd()
{
	name = nullptr;
}

Classic::~Classic()
{
	delete[] name;
}

void Classic::Report() const
{
	using std::cout;
	Cd::Report();
	if (!name)
		cout << "name:\t" << name << "\n";
}

Classic& Classic::operator=(const Classic& cl)
{
	if (this == &cl)
		return *this;
	Cd::operator=(cl);
	delete[] name;
	name = new char[strlen(cl.name) + 1];
	strcpy_s(name, strlen(cl.name) + 1, cl.name);
	return *this;
}