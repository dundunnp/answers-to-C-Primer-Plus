// 1
#include <iostream>
using namespace std;

int main()
{	
	const int FOOT_TO_INCH = 12;
	int height;
	
	cout << "�����������ߣ���λΪӢ�磩��_____\b\b\b\b\b";
	cin >> height;
	cout << "������Ϊ:\n";
	cout << height << " Ӣ�� = " << height / FOOT_TO_INCH << " Ӣ�� " << height % FOOT_TO_INCH << " Ӣ��";
	return 0;
}

// 2
#include <iostream>
using namespace std;

int main()
{	
	const int FOOT_TO_INCH{ 12 };
	const double INCH_TO_M{ 0.0254 };
	const double POUND_TO_KG{1/2.2};
	int foot, inch;
	double pound, BMI, height, weight;
	
	cout << "�����������ߣ�����λΪӢ�ߣ�";
	cin >> foot;
	cout << "����λΪӢ�磩";
	cin >> inch;
	cout << "�������������:����λΪ����";
	cin >> pound;
	height = (foot * FOOT_TO_INCH + inch) * INCH_TO_M;
	weight = pound * POUND_TO_KG;
	BMI = weight / height / height;
	cout << "�������ָ��BMIΪ" << BMI;
	return 0;
}

// 3
#include <iostream>
using namespace std;

int main()
{
	const double DEGREES_TO_MINUTES{ 60 };
	const double MINUTES_TO_SECONDS{ 60 };
	int degrees, minutes, seconds;

	cout << "Enter a latitude in degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;
	double ans = degrees + double(minutes) / DEGREES_TO_MINUTES + double(seconds) / MINUTES_TO_SECONDS / DEGREES_TO_MINUTES;
	cout << degrees << " degrees, "
		<< minutes << " minutes, "
		<< seconds << " seconds = "
		<< ans << " degrees";
	return 0;
}

// 4
#include <iostream>
using namespace std;

int main()
{
	const int DAYS_TO_HOURS = 24;
	const int HOURS_TO_MINUTES = 60;
	const int MINUTES_TO_SECONDS = 60;
	long long seconds;
	int days, hours, minutes, second;

	cout << "Enter the number of seconds: ";
	cin >> seconds;
	days = seconds / (DAYS_TO_HOURS * HOURS_TO_MINUTES * MINUTES_TO_SECONDS);
	hours = (seconds % (DAYS_TO_HOURS * HOURS_TO_MINUTES * MINUTES_TO_SECONDS)) / (HOURS_TO_MINUTES * MINUTES_TO_SECONDS);
	minutes = (seconds % (DAYS_TO_HOURS * HOURS_TO_MINUTES * MINUTES_TO_SECONDS)) % (HOURS_TO_MINUTES * MINUTES_TO_SECONDS) / MINUTES_TO_SECONDS;
	second = (seconds % (DAYS_TO_HOURS * HOURS_TO_MINUTES * MINUTES_TO_SECONDS)) % (HOURS_TO_MINUTES * MINUTES_TO_SECONDS) % MINUTES_TO_SECONDS;
	cout << seconds << " seconds = "
		<< days << " days, "
		<< hours << " hours, "
		<< minutes << " minutes, "
		<< second << " seconds";
	return 0;
}

// 5
#include <iostream>
using namespace std;

int main()
{	
	long long world_population, US_population;
	double population_percent;

	cout << "Enter the world's population: ";
	cin >> world_population;
	cout << "Enter the population of US: ";
	cin >> US_population;
	population_percent = double(US_population) / world_population * 100;
	cout << "The population of the US is " << population_percent << "%" << " of the world population.";
	return 0;
}

// 6
#include <iostream>
using namespace std;

int main()
{	
	double mile, gallon, km, L;
	cout << "������������̣���λ��Ӣ�: ";
	cin >> mile;
	cout << "������ʹ������������λ�Ǽ��أ�: ";
	cin >> gallon;
	cout << "�����ͺ�Ϊ��" << mile / gallon << endl;
	cout << "��Ҳ����������루��λ��ǧ�ף�: ";
	cin >> km;
	cout << "��������������λ������: ";
	cin >> L;	
	cout << "ŷ�޷��ĺ�����Ϊ: " << L / km * 100;
	return 0;
}

// 7
#include <iostream>
using namespace std;

int main()
{
	const float KM_TO_MILE = 62.14;
	const float GALLON_TO_L = 3.785;
	double fuel_consume_eur, fuel_consume_us;
	
	cout << "Enter the fuel consume in europe(l/100km): ";
	cin >> fuel_consume_eur;
	fuel_consume_us = (KM_TO_MILE * GALLON_TO_L) / fuel_consume_eur;
	cout << "The fuel consume is " << fuel_consume_eur << "L/100KM." << endl;
	cout << "The fuel consume is " << fuel_consume_us << " mile/gallon.";
	return 0;
}