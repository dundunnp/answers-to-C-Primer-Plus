#pragma once
#ifndef C10_8_H_
#define C10_8_H_

typedef unsigned int Item;

void add(Item& item);
void sub(Item& item);
void mul(Item& item);
void div(Item& item);

class List
{
private:
	static const int Max = 10;
	Item list[Max];
	int top;
public:
	List();
	void append(const Item& item);
	bool isempty() const;
	bool isfull() const;
	void visit(void (*pf)(Item& item));
	void show() const;
};
#endif 