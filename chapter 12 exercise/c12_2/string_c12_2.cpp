#include "c12_2.h"
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;

String::String(const char* ch)
{
	len = strlen(ch);
	str = new char[len + 1];
	strcpy(str, ch);
}

String::String()
{
	len = 0;
	str = nullptr;
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

String::~String()
{
	delete[] str;
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

int String::has(char ch) const
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ch)
			count++;
	}
	return count;
}

String& String::operator=(const String& s)
{
	if (this == &s)
		return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
	if (s.str)
		os << s.str;
	else
		os << "nothing";
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		s = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
} 

String operator+(const String& s1, const String& s2)
{	
	String temp;
	temp.len = s1.len + s2.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, s1.str);
	strcat(temp.str, s2.str);
	return temp;
}

String operator+(const char* ch, const String& s)
{
	String temp;
	temp.len = strlen(ch) + s.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, ch);
	strcat(temp.str, s.str);
	return temp;
}

bool operator==(const String& s1, const String& s2)
{
	return (strcmp(s1.str, s2.str) == 0);
}