#pragma once
#ifndef C10_2_H_
#define C10_2_H_

#include <iostream>
#include <string>

using std::string;

class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string& ln, const char* fn = "Heyyou");
	void Show() const;
	void FormalShow() const;
};
#endif
