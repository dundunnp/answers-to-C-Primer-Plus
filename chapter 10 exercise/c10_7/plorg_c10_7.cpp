#include "c10_7.h"
#include <iostream>
#include <cstring>

Plorg::Plorg(const char* nm, int ci)
{
	strcpy_s(name, nm);
	CI = ci;
}

void Plorg::setCI(int ci)
{
	CI = ci;
}

void Plorg::setCI()
{	
	using namespace std;
	int temp;
	cout << "You need to reset the CI value for " << name << endl;
	while (!(cin >> temp))
	{
		cin.clear();
		while (cin.get() != '\n') continue;
		cout << "illegal, please reenter the CI: " << endl;
	}
	cin.get();
	CI = temp;
}

void Plorg::show() const
{
	std::cout << "name: " << name << ", CI = " << CI << std::endl;
}