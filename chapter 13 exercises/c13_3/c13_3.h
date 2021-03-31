#pragma once
#ifndef C13_3_H_
#define C13_3_H_

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

// base class
class ABC
{
public:
	virtual ~ABC() {};
	virtual void View() const { cout << "This is ABC View(), it is empty.\n"; };
};

// derived class

class baseDMA : public ABC
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	virtual void View() const;
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};


class lacksDMA : public baseDMA
{
private:
	static const int COL_LEN = 40;
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	virtual void View() const;
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA : public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA() { delete[] style; };
	virtual void View() const;
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};
#endif 