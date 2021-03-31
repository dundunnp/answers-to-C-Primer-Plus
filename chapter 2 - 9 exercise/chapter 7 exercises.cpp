// 1
#include <iostream>
using namespace std;
inline double harmean(double x, double y) 
{ 
	return 2.0 * x * y / (x + y);
}

int main()
{
	double a, b;
	while (cin >> a >> b && a != 0 && b != 0)
	{
		cout << harmean(a, b) << endl;
	}
	return 0;
}

// 2
#include <iostream>
using namespace std;
const int Max = 10;

int set_mark(int arr[], int size);
void show_mark(int arr[], int size);
double average_mark(int arr[], int size);

int main()
{	
	int goal[Max];
	int size = set_mark(goal, 10);
	show_mark(goal, size);
	cout << "\naverage: " << average_mark(goal, size);
	return 0;
}

int set_mark(int arr[], int max)
{	
	int i = 0;
	for (i; i < max; i++)
	{
		cout << i + 1 << ":";
		cin >> arr[i];
		cin.get();
		cout << "press enter to continue, or 'q' for STOP input: ";
		if (cin.get() == 'q')
		{
			break;
		}
	}
	return i;
}

void show_mark(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << i + 1 << ":" << arr[i] << "\t";
}

double average_mark(int arr[], int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
}

// 3
#include <iostream>
using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(box b);
void cal_volume(box* b);

int main()
{
	box box1 = { "China", 13.14, 16.3, 79,5 };
	cal_volume(&box1);
	show_box(box1);
	return 0;
}

void show_box(box b)
{
	cout << "maker: " << b.maker << endl;
	cout << "height: " << b.height << endl;
	cout << "width: " << b.width << endl;
	cout << "length: " << b.length << endl;
	cout << "volume: " << b.volume << endl;
}

void cal_volume(box* b)
{
	b->volume = b->height * b->length * b->width;
}

// 4
#include <iostream>
long double probability(unsigned numbers, unsigned picks);
int main()
{
	using namespace std;
	cout << probability(47, 5) * probability(27, 1);
	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	unsigned p, n;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result *= n / p;
	return result;
}

// 5
#include <iostream>
using namespace std;

long double factorial(int n);

int main()
{
	int n;
	while (cin >> n && n >= 0)
		cout << n << "! = " << factorial(n) << endl;
	return 0;
}

long double factorial(int n)
{
	if (n < 2)
		return 1;
	else
		return n * factorial(n - 1);
}

// 6
#include <iostream>
using namespace std;
int Fill_array(double arr[], int max);
void Show_array(double arr[], int size);
void Reverse_array(double arr[], int size);

const int Max = 10;

int main()
{	
	double arr[Max];
	int size = Fill_array(arr, Max);
	Show_array(arr, size);
	cout << "反转数组\n";
	Reverse_array(arr, size);
	Show_array(arr, size);
	cout << "反转数组中除第1个和最后一个元素之外的所有元素\n";
	Reverse_array(arr + 1, size - 2);
	Show_array(arr, size);
	return 0;
}

int Fill_array(double arr[], int max)
{	
	int size = 0;
	for (size; size < max; size++)
	{
		cout << size + 1 << ":";
		if (cin >> arr[size]);
		else break;
	}
	return size;
}

void Show_array(double arr[], int size)
{	
	for (int i = 0; i < size; i++)
		cout << i + 1 << " : " << arr[i] << endl;
}

void Reverse_array(double arr[], int size)
{
	double temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}

// 7
#include <iostream>
using namespace std;
const int Max = 5;

double* fill_array(double* begin, double* end);
void show_array(double* begin, double* end);
void revalue(double* begin, double* end, double r);

int main()
{
	double properties[Max];
	double* pa = fill_array(properties, properties + Max);
	show_array(properties, pa);
	cout << "Enter revaluation factor: ";
	double factor;
	if (properties != pa)
	{
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(properties, pa, factor);
		show_array(properties, pa);
	}
	cout << "Done.\n";
	return 0;
}

double* fill_array(double* begin, double* end)
{
	int i = 1;
	while (begin != end)
	{	
		cout << "Enter value #" << i++ << ": ";
		cin >> *begin;
		begin++;
	}
	return begin++;
}

void show_array(double* begin, double* end)
{	
	int i = 1;
	while (begin != end)
	{
		cout << "Property #" << i++ << ": $";
		cout << *begin << endl;
		begin++;
	}
}

void revalue(double* begin, double* end, double r)
{
	while (begin != end)
	{
		*begin *= r;
		begin++;
	}	
}

// 8a
#include <iostream>
#include <string>
using namespace std;
const int Seasons = 4;
const char* Sname[4] = { "Spring", "Summer", "Fall", "Winter" };

void fill(double arr[]);
void show(const double arr[]);

int main()
{
	double expenses[Seasons];
	fill(expenses);
	show(expenses);
	return 0;
}

void fill(double arr[])
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Sname[i] << " expenses: ";
		cin >> arr[i];
	}
}

void show(const double arr[])
{	
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << ": $" << arr[i] << endl;
		total += arr[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

// 8b
#include <iostream>
#include <string>
using namespace std;
const int Seasons = 4;
const char* Sname[4] = { "Spring", "Summer", "Fall", "Winter" };

struct spend
{
	double expense[Seasons];
};

void fill(spend* money);
void show(const spend cost);

int main()
{
	spend expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(spend* money)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Sname[i] << " expenses: ";
		cin >> money->expense[i];
	}
}

void show(const spend cost)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << ": $" << cost.expense[i] << endl;
		total += cost.expense[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

// 9
#include <iostream>
using namespace std;
const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* st);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered - 1; i++)
	{	
		cout << "第" << i + 1 << "位同学的信息：\n";
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	cout << "所有同学的信息：\n";
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done.\n";
	return 0;
}

int getinfo(student pa[], int n)
{
	int entered = 0;
	while (entered < n)
	{	
		cout << "请输入第" << entered + 1 << "个学生的信息：\n";
		cout << "fullname: ";
		if (!cin.getline(pa[entered].fullname, SLEN))
			break;
		cout << "hobby: ";
		cin.getline(pa[entered].hobby, SLEN);
		cout << "ooplevel: ";
		cin >> pa[entered].ooplevel;
		cin.get();
		entered++;
	}
	return entered + 1;
}

void display1(student st)
{	
	cout << "fullname(1): " << st.fullname << endl;
	cout << "hobby(1): " << st.hobby << endl;
	cout << "ooplevel(1): " << st.ooplevel << endl;
}

void display2(const student* st)
{
	cout << "fullname(2): " << st->fullname << endl;
	cout << "hobby(2): " << st->hobby << endl;
	cout << "ooplevel(2): " << st->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		cout << "fullname: " << pa[i].fullname << endl;
		cout << "hobby: " << pa[i].hobby << endl;
		cout << "ooplevel: " << pa[i].ooplevel << endl;
	}
}

// 10
#include <iostream>
#include <string>
using namespace std;
const char* operter[3] = { " + ", " * ", " - " };

double add(double x, double y);
double mul(double x, double y);
double sub(double x, double y);
double calculate(double x, double y, double (*pf)(double , double));

int main()
{	
	double x, y;
	double (*pf[3])(double x, double y) = {add, mul, sub};
	while (cin >> x >> y)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << x << operter[i] << y << " = " << pf[i](x, y) << endl;
		}
	}
	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double mul(double x, double y)
{
	return x * y;
}

double sub(double x, double y)
{
	return x - y;
}

double calculate(double x, double y, double (*pf)(double , double))
{
	return (*pf)(x, y);
}
