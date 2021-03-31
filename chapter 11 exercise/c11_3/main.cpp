#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "c11_3.h"

int main()
{
	using namespace std;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	unsigned long Max = 0;
	unsigned long Min = 0;
	unsigned long Sum = 0;
	unsigned int count = 0;

	int N;
	cout << "Enter the number of tests N: ";
	while (!(cin >> N))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "illegal, please reenter: ";
	}

	cout << "Enter target distance (q to quit): ";
	if (!(cin >> target))
		return 0;
	cout << "Enter step length: ";
	if (!(cin >> dstep))
		return 0;
	cout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
	while (count < N)
	{	
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		Max = max(Max, steps);
		if (Min == 0)
			Min = Max;
		Min = min(Min, steps);
		Sum += steps;
		steps = 0;
		result.reset(0.0, 0.0);
		count++;
	}
	cout << "Your input " << N << " times, and statistics info: " << endl;
	cout << "Max step = " << Max << endl;
	cout << "Min step = " << Min << endl;
	cout << "Average step = " << Sum / N << endl;

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}