#include <iostream>
#include <cstdlib>
#include <ctime>
#include "c12_6.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	using std::cout;
	using std::cin;
	using std::ios_base;
	using std::endl;

	srand(time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;

	Queue line1(qs);
	Queue line2(qs);

	cout << "Enter the number of simulation hours (>= 100): ";
	int hours;
	cin >> hours;

	long cyclelimit = MIN_PER_HR * hours;

	double perhour = 0;

	Item temp;
	double average_wait = 0;
	//long turnaways = 0;
	//long customers = 0;
	//long sum_line = 0;
	//int wait_time = 0;
	long served, line_wait;
	int wait_time1, wait_time2;
	while (average_wait < 1)
	{
		perhour++;
		served = line_wait = wait_time1 = wait_time2 = 0;
		while (!line1.isempty()) line1.dequeue(temp);
		while (!line2.isempty()) line2.dequeue(temp);
		double min_per_cust = MIN_PER_HR / perhour;
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (!line1.isfull() && line1.queuecount() < line2.queuecount())
				{
					temp.set(cycle);
					line1.enqueue(temp);
				}
				else if (!line2.isfull() && line1.queuecount() >= line2.queuecount())
				{
					temp.set(cycle);
					line2.enqueue(temp);
				}
			}
			if (wait_time1 <= 0)
			{	
				if (!line1.isempty())
				{
					line1.dequeue(temp);
					wait_time1 = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
			if (wait_time2 <= 0)
				if (!line2.isempty())
				{
					line2.dequeue(temp);
					wait_time2 = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
			}
			if (wait_time1 > 0)
				wait_time1--;
			if (wait_time2 > 0)
				wait_time2--;
		}
		average_wait = line_wait / served;
	}

	cout << "customers served: " << served << endl;
	cout << "average number of customers per hour: " << perhour << endl;
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << " average wait time: " << (double)line_wait / served << " minutes\n";
	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}