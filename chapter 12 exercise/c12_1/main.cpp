#include "c12_1.h"
#include <iostream>

int main()
{	
	using namespace std;
	{
		Cow cow_list[2] = { {"Tom", "Sleeppy", 200} };
		cow_list[0].ShowCow();
		cow_list[1].ShowCow();
		cow_list[1] = cow_list[0];
		cow_list[1].ShowCow();
		Cow copy(cow_list[1]);
		copy.ShowCow();
	}
	cout << "Done!";
	cin.get();
	return 0;
}