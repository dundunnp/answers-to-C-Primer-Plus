#include "c12_4.h"
#include <iostream>

Stack::Stack(int n)
{	
	using std::cout;
	if (n > MAX)
	{
		cout << "The stack can only store up to " << MAX << " elements\n";
		cout << "The stack size set to " << MAX << ".\n";
		size = MAX;
	}
	else if (n < 0)
	{
		cout << "Stack size cannot be negative\n";
		cout << "The stack size set to 0\n";
		size = 0;
	}
	else
		size = n;
	top = 0;
	pitems = new Item[size];
}

Stack::Stack(const Stack& st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
	if (pitems != nullptr) delete[] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item& item)
{
	if (top >= size)
		return false;
	pitems[top++] = item;
	return true;
}

bool Stack::pop(Item& item)
{
	if (top <= 0)
		return false;
	item = pitems[--top];
	return true;
}

Stack& Stack::operator=(const Stack& st)
{
	if (this == &st)
		return *this;
	delete[] pitems;
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = st.pitems[i];
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack& st)
{
	for (int i = 0; i < st.top; i++)
		os << "[" << i << "]\t";
	os << "\n";
	for (int i = 0; i < st.top; i++)
		os << st.pitems[i] << "\t";
	os << "\n";
	return os;
}