#pragma once
#ifndef C10_7_H_
#define C10_7_H_

class Plorg
{
	static const int SIZE = 19;
	char name[SIZE];
	int CI;
public:
	Plorg(const char* nm = "no name", int ci = 50);
	void setCI(int ci);
	void setCI();  // interactive
	void show() const;
};

#endif 