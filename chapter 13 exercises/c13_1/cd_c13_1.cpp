#include "c13_1.h"
#include <cstring>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy_s(performers, s1);
	strcpy_s(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

void Cd::Report() const
{	
	using std::cout;
	using std::endl;
	cout << "performers:\t" << performers << endl;
	cout << "label:\t" << label << endl;
	cout << "selections:\t" << selections << endl;
	cout << "playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* nm, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	strcpy_s(name, nm);
}

Classic::Classic(const Classic& cl) : Cd(cl)
{
	strcpy_s(name, cl.name);
}

Classic::Classic() : Cd()
{
	name[0] = '\0';
}

void Classic::Report() const
{
	using std::cout;
	Cd::Report();
	cout << "name:\t" << name << "\n";
}

Classic& Classic::operator=(const Classic& d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	strcpy_s(name, d.name);
	return *this;
}