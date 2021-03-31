#include "c12_1.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
	hobby = nullptr;
	name[0] = '\0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{	
	strncpy(name, nm, 20);
	if (strlen(nm) >= 20) name[19] = '\0';
	else name[strlen(nm)] = '\0';
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{	
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{	
	std::cout << name << " is gone\n";
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	else
	{
		delete[] hobby;
		strcpy(name, c.name);
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
		weight = c.weight;
		return *this;
	}
}

void Cow::ShowCow() const
{	
	if (hobby == nullptr)
	{
		std::cout << "nothing\n";
		return;
	}
	else 
	{
		std::cout << "name: " << name << std::endl
			<< "hobby: " << hobby << std::endl
			<< "weight: " << weight << std::endl;
	}
}