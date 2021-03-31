#pragma once
#ifndef C13_2_H_
#define C13_2_H_
#include <iostream>
// base class
class Cd
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	virtual Cd& operator=(const Cd& d);
};

// derived class
class Classic : public Cd
{
private:
	char* name;
public:
	Classic(const char* nm, const char* s1, const char* s2, int n, double x);
	Classic(const Classic& cl);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	virtual Classic& operator=(const Classic& d);
};
#endif // !C13_2_H_
