// 1
#include <iostream>
using namespace std;

int main()
{
	cout << "夏子谆" << endl;
	cout << "江西省南昌市红谷滩新区";
	return 0;
}

//2
#include <iostream>

double long_tran_yard(double);

int main()
{	
	using namespace std;
	double Long;
	cout << "请输入一个以long为单位的距离： ";
	cin >> Long;
	cout << Long << " long = " << long_tran_yard(Long) << " yard";
	return 0;
}

double long_tran_yard(double Long)
{
	return Long* 220;
}

//3
#include <iostream>

using namespace std;

void print_blind();
void print_run();

int main()
{
	print_blind();
	print_blind();
	print_run();
	print_run();
	return 0;
}

void print_blind()
{
	cout << "Three blind mice" << endl;
}

void print_run()
{
	cout << "See how they run" << endl;
}

//4
#include <iostream>

int main()
{
	using namespace std;
	int Age;
	cout << "Enter your age: ";
	cin >> Age;
	cout << "You are " << 12 * Age << " months old.";
	return 0;
}

//5
#include <iostream>

double C_tran_F(double);

int main()
{
	using namespace std;
	double C_val;
	cout << "Please enter a Celsius value: ";
	cin >> C_val;
	double F_val = C_tran_F(C_val);
	cout << C_val << " degrees Celsius is " << F_val << " degrees Fahrenheit.";
	return 0;
}

double C_tran_F(double f_val)
{
	return f_val * 1.8 + 32.0;
}

//6
#include <iostream>

double convert(double);

int main()
{
	using namespace std;
	double light_years;
	cout << "Enter the number of light years: ";
	cin >> light_years;
	cout << light_years << " light years = " << convert(light_years) << " astronomical units.";
	return 0;
}

double convert(double light_years)
{
	return light_years * 63240;
}

//7
#include <iostream>

using namespace std;

void print_time(double, double);

int main()
{
	double hours;
	double minutes;
	cout << "Enter the number of hours: ";
	cin >> hours;
	cout << "Enter the number of minutes: ";
	cin >> minutes;
	print_time(hours, minutes);
	return 0;
}

void print_time(double hours, double minutes)
{
	cout << "Time: " << hours << ":" << minutes;
}