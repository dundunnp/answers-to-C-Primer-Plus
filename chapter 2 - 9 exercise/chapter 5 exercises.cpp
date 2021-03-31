// 1
#include <iostream>

int main()
{
	using namespace std;
	int min_num, max_num, sum_num;
	sum_num = 0;
	cout << "计算并输出两个整数之间所有整数的和\n";
	cout << "请输入较小的整数：";
	cin >> min_num;
	cout << "请输入较大的整数：";
	cin >> max_num;
	for (min_num; min_num < max_num + 1; min_num++)
		sum_num += min_num;
	cout << "整数和为：" << sum_num;
	return 0;
}

// 2
#include <iostream>
#include <array>

const int ArSize = 16;

int main()
{
	using namespace std;
	array<long double, 101> factorials;
	factorials[0] = factorials[1] = 1;
	for (int i = 2; i < 101; i++)
		factorials[i] = i * factorials[i - 1];
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;
	cout << "101! = " << factorials[100];
	return 0;
}

// 3
#include <iostream>

int main()
{
	using namespace std;
	int num, sum = 0;
	cout << "请输入数字（输入0中止）";
	cin >> num;
	while (num)
	{
		sum += num;
		cout << "输入的累计和为：" << sum << endl;
		cout << "请输入数字（输入0中止）";
		cin >> num;
	}
	return 0;
}

// 4
#include <iostream>

int main()
{
	using namespace std;
	const float d_profit = 0.1, c_profit = 0.05;
	const int deposit_base = 100;
	int d_deposit = deposit_base, c_deposit = deposit_base, year = 0;
	
	while (d_deposit >= c_deposit)
	{
		d_deposit += (deposit_base * d_profit);
		c_deposit += (c_deposit * c_profit);
		year++;
	}
	cout << "经过" << year << "多年, Cleo的投资价值超过了Daphne的投资价值\n";
	cout << "Cleo的资产为：" << c_deposit << endl;
	cout << "Daphne的资产为：" << d_deposit << endl;
	return 0;
}

// 5
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	const int months = 12;
	int sell_month[months];
	string month[months] = {"一月", "二月", "三月", "四月", "五月", "六月", 
		"七月", "八月", "九月", "十月", "十一月", "十二月"};
	for (int i = 0; i < months; i++)
	{
		cout << "请输入" << month[i] << "的销售量：";
		cin >> sell_month[i];
	}
	int sell_year = 0;
	for (int i = 0; i < months; i++)
	{
		cout << month[i] << "的销售量:\t" << sell_month[i] << endl;
		sell_year += sell_month[i];
	}
	cout << "今年的总销售量:\t" << sell_year;
	return 0;
}

// 6
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	const string month[12] = { "一月", "二月", "三月", "四月", "五月", "六月",
		"七月", "八月", "九月", "十月", "十一月", "十二月" };
	const string year[3] = { "第一年", "第二年","第三年" };
	int sell[12][3], sell_year[3] = {}, sell_all_year = 0;
	for (int i = 0; i < 3; i++)
	{	
		cout << "请输入" << year[i] << "每月销售量情况：" << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << "请输入" << month[j] << "的销售量：";
			cin >> sell[j][i];
			sell_year[i] += sell[j][i];
			sell_all_year += sell[j][i];
		}
	}
	for (int i = 0; i < 3; i++)
		cout << year[i] << "的总销售量：\t" << sell_year[i] << endl;
	cout << "三年的总销售量:\t" << sell_all_year;
	return 0;
}

// 7
#include <iostream>
#include <string>
using namespace std;

struct car 
{
	string producer;
	int year_production;
};

int main()
{	
	int car_num;
	cout << "How many cars do you wish to catalog? ";
	cin >> car_num;
	car* pt = new car[car_num];
	for (int i = 0; i < car_num; i++)
	{	
		cin.get();
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Please enter the make: ";
		getline(cin, pt[i].producer);
		cout << "Please enter the year made: ";
		cin >> pt[i].year_production;
	}
	cout << "Here is your collection:\n";
	for (int i = 0; i < car_num; i++)
		cout << pt[i].year_production << " " << pt[i].producer << endl;
	delete[] pt;
	return 0;
}

// 8
#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	int counter = 0;
	char word[20];
	const char quit[5] = "done";
	cout << "Enter words (to stop, type the word done):\n";
	while (strcmp(quit, word))
	{
		cin >> word;
		counter++;
		cin.get();
	}
	cout << "You entered a total of " << counter - 1 << " words.";
	return 0;
}

// 9
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	int counter = 0;
	string word;
	const string quit = "done";

	cout << "Enter words (to stop, type the word done):\n";
	while (quit != word)
	{
		cin >> word;
		counter++;
		cin.get();
	}
	cout << "You entered a total of " << counter - 1 << " words.";
	return 0;
}

// 10
#include <iostream>

int main()
{
	using namespace std;
	
	int row_num;
	cout << "Enter number of rows: ";
	cin >> row_num;
	for (int i = 1; i < row_num + 1; i++)
	{
		for (int dot = 0; dot < row_num - i; dot++)
			cout << ".";
		for (int star = 0; star < i; star++)
			cout << "*";
		cout << endl;
	}
}
