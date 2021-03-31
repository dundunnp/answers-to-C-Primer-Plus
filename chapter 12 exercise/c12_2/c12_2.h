#pragma once
#ifndef C12_2_H_
#define C12_2_H_
#include <iostream>
using std::ostream;
using std::istream;
class String
{
private:
	char* str;
	int len;
	static const int CINLIM = 80;
public:
	String(const char* ch);
	String();
	String(const String& s);
	~String();
	int length() const { return len; }
	void stringup();
	void stringlow();
	int has(char ch) const;

	String& operator=(const String& s);
	String& operator=(const char* s);

	friend bool operator==(const String& s1, const String& s2);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	friend String operator+(const String& s1, const String& s2);
	friend String operator+(const char* ch, const String& s);
	friend String operator+(String& s, const char* ch) { return ch + s; }
};

#endif // !1
