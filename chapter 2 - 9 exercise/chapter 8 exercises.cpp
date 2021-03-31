// 1
#include <iostream>
using namespace std;
int func_count = 0;
void display(const char* str, int n = 0);
int main()
{	
	display("dundun");
	display("dundun");
	display("dundun", 1);
	return 0;
}

void display(const char* str, int n)
{
	func_count++;
	if (n == 0)
	{
		cout << "Arguments = 0;\n";
		cout << str << endl;
	}
	else
	{
		cout << "Arguments != 0;\n";
		for (int i = 0; i < func_count; i++)
			cout << str << endl;
	}
}

// 2
#include <iostream>
#include <cstring>
using namespace std;

struct CandyBar
{
	char name[20];
	double weight;
	int heat;
};

void set_candybar(CandyBar& cb, const char* ch = "Millennium Munch", double wt = 2.85, int h = 350);
void show_candybar(const CandyBar& cb);

int main()
{
	CandyBar cb;
	set_candybar(cb);
	show_candybar(cb);
	set_candybar(cb, "China", 2.99, 360);
	show_candybar(cb);
	return 0;
}

void set_candybar(CandyBar& cb, const char* ch, double wt, int h )
{
	strcpy_s(cb.name, ch);
	cb.weight = wt;
	cb.heat = h;
}

void show_candybar(const CandyBar& cb)
{
	cout << "The candybar is made by " << cb.name;
	cout << " and its weight " << cb.weight << ", ";
	cout << cb.heat << " calorie" << endl;
}

// 3
#include <iostream>
#include <string>
using namespace std;
void upper(string& str);

int main()
{
	cout << "Enter a string (q to quit): ";
	string str;
	while (getline(cin, str), str != "q")
	{
		upper(str);
		cout << "Next string (q to quit): ";
	}
	cout << "Bye.";
	return 0;
}

void upper(string& str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	cout << str << endl;
}

// 4
#include <iostream>
using namespace std;
#include <cstring>
struct stringy
{
	char* str;
	int ct;
};

void set(stringy& sty, char* ch);
void show(const string& str, int n = 1);
void show(const stringy& sty, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	return 0;
}

void set(stringy& sty, char* ch)
{
	sty.ct = strlen(ch);
	sty.str = new char[sty.ct];
	strcpy(sty.str, ch);
}

void show(const string& str, int n)
{
	if (n < 1)
		cout << "illegal" << endl;
	else
	{
		for (int i = 0; i < n; i++)
			cout << str << endl;
	}
}

void show(const stringy& sty, int n)
{
	if (n < 1)
		cout << "illegal" << endl;
	else
	{	
		for (int i = 0; i < n; i++)
			cout << sty.str << endl;
	}
}

// 5
#include <iostream>
using namespace std;
const int Size = 5;
template <typename T> T max5(const T arr[Size]);

int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	double arr2[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	cout << "The Max Element of int array: " << max5(arr1) << endl;
	cout << "The Max Element of double array: " << max5(arr2) << endl;
	return 0;
}

template <typename T> T max5(const T arr[Size])
{
	T max_num = arr[0];
	for (int i = 1; i < Size; i++)
		max_num = max_num < arr[i] ? arr[i] : max_num;
	return max_num;
}

// 6
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template <typename T> T maxn(T arr[], int size);
template <> const char* maxn<const char*>(const char* str[], int size);
int main()
{
	int arr1[6] = { 1, 2, 3, 4, 5, 6 };
	double arr2[4] = { 1.0, 2.0, 3.0, 4.0 };
	const char* str1[5] = { "xiazizhun", "dundun", "dundunnppp", "xiazihan", "xiazidun" };
	const char* str2[5] = { "zizhun", "dun", "dundunnp", "xiahan", "zidun" };
	const char* str3[] = { "Hello", "Hello world" };
	cout << "The Max Element of int array: " << maxn(arr1, 6) << endl;
	cout << "The Max Element of double array: " << maxn(arr2, 4) << endl;
	cout << "The Max Element of string: " << maxn(str1, 5) << endl;
	cout << "The Max Element of string: " << maxn(str2, 5) << endl;
	cout << "The Max Element of string: " << maxn(str3, 2) << endl;
	return 0;
}

template <typename T> T maxn(T arr[], int size)
{
	T max_num = arr[0];
	for (int i = 1; i < size; i++)
		max_num = max_num < arr[i] ? arr[i] : max_num;
	return max_num;
}

template <> const char* maxn<const char*>(const char* str[], int size)
{
	int pos = 0;
	for (int i = 1; i < size; i++)
	{	
		if (strlen(str[pos]) < strlen(str[i]))
		{
			pos = i;
		}
	}
	return str[pos];
}

// 7
#include <iostream>
using namespace std;
template <typename T> void SumArray(T arr[], int n);
template <typename T> void SumArray(T* arr[], int n);
struct debts
{
	char name[20];
	double amount;
};

int main()
{
	int things[6] = { 13, 31, 103, 301, 310 ,130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1330.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	cout << "The sum of things: ";
	SumArray(things, 6);
	cout << "The sum of pd: ";
	SumArray(pd, 3);
	return 0;
}

template <typename T> void SumArray(T arr[], int n)
{
	T total = arr[0];
	for (int i = 1; i < n; i++)
		total += arr[i];
	cout << total << endl;
}

template <typename T> void SumArray(T* arr[], int n)
{
	T total = *arr[0];
	for (int i = 1; i < n; i++)
		total += *arr[i];
	cout << total << endl;
}