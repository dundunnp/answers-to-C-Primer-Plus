#pragma once
#ifndef C12_3_H_
#define C12_3_H_

#include <iostream>
using std::cout;
using std::ostream;

class Stock
{
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	~Stock();
	Stock(const char* co, long n = 0, double pr = 0.0);
	Stock(const Stock& s);
	Stock& operator=(const Stock& s);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;
	friend ostream& operator<<(ostream& os, const Stock& s);
};
#endif // !C12_3_H_
