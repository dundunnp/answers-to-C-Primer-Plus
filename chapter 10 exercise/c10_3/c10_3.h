#pragma once
#ifndef C10_3_H_
#define C10_3_H_

#include <iostream>


class golf
{
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	golf(const char* name, int hc);
	golf();
	void sethandicap(int hc);
	void showgolf() const;
};
#endif