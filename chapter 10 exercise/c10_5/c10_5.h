#pragma once
#ifndef C10_5_H_
#define C10_5_H_
struct customer
{
	char fullname[35];
	double payment;
};

typedef customer Item;

class Stack
{
	enum {Max = 2};
	Item items[Max];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
};
#endif