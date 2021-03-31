#include "c10_5.h"
#include <iostream>

Stack::Stack()
{	
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{	
	return top == Max;
}

bool Stack::push(const Item& item)
{
	if ((*this).isfull())
		return false;
	items[top++] = item;
	return true;
}

bool Stack::pop(Item& item)
{	
	if (top <= 0)
		return false;
	else
	{
		item = items[--top];
		return true;
	}
}