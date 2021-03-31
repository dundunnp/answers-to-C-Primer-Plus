#include <iostream>
#include "c11_6.h"

int main()
{
	using std::endl;
	using std::cin;
	using std::cout;
	const int SIZE = 6;
	Stonewt arr[SIZE] = {12, Stonewt(10, 0.35), 8};
	Stonewt max = arr[0];
	Stonewt min = arr[0];
	Stonewt eleven = Stonewt(11, 0.0);
	int count = 0;
	double input;
	for (int i = 3; i < SIZE; i++)
	{
		cout << "enter the No." << i + 1 << "'s element info(in pounds): ";
		cin >> input;
		arr[i] = Stonewt(input);
		while (cin.get() != '\n')
			continue;
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
		if (arr[i] > eleven) count++;
	}

	cout << "The weight max: " << max;
	cout << "\nThe weight min: " << min;
	cout << "\nHeavy than eleven: " << count << endl;
	return 0;

}