// 1 please use c9_1 file

// 2
#include <string>
#include <iostream>
using namespace std;
void strcount(const string str);

int main()
{
	string input;

	cout << "Enter a line:\n";
	getline(cin, input);
	while (cin)
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
		if (input == "")
			break;
	}
	cout << "Bye\n";
	return 0;
}

void strcount(const string str)
{
	static int total = 0;
	int count = 0;
	cout << "\"" << str << "\" contains ";
	count = str.size();
	total += count;
	cout << count << " charcaters\n";
	cout << total << " charcaters total\n";
}

// 3
#include <iostream>
#include <cstring>
#include <new>

using namespace std;

struct chaff
{
	char dross[20];
	int slag;

};

void set(chaff&);
void show(const chaff&);
char buffer[520];

int main()
{	
	chaff* p1, * p2;
	p1 = new (buffer) chaff[2];
	p2 = new chaff[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "#" << i + 1 << ":\n";
		cout << "static:\n";
		set(p1[i]);
		cout << "heap:\n";
		set(p2[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "#" << i + 1 << ":\n";
		cout << "static:\n";
		show(p1[i]);
		cout << "heap:\n";
		show(p2[i]);
	}
	delete[] p1; 
	delete[] p2;                   
	return 0;

}

void set(chaff& ch)
{	
	char temp[20];
	cout << "dross: ";
	cin.getline(temp, 20);
	strcpy_s(ch.dross, temp);
	cout << "slag: ";
	while (!(cin >> ch.slag))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "illegal, please re-enter:";
	}
	cin.get();
}

void show(const chaff& ch)
{	
	cout << "dross: " << ch.dross << endl;
	cout << "slag: " << ch.slag << endl;
}

// 4 please use C9_4 file
