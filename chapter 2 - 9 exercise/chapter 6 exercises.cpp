// 1
#include <iostream>
#include <cctype>
int main()
{
	using namespace std;
	char ch;
	while (cin.get(ch) && ch != '@')
	{	
		if (isdigit(ch))
			continue;
		else if (isupper(ch))
		{
			ch = tolower(ch);
			cout << ch;
		}
		else
		{
			ch = toupper(ch);
			cout << ch;
		}			
	}
	return 0;
}

// 2
#include <iostream>

int main()
{
	using namespace std;
	const int Max = 10;

	double donation[Max];
	int i = 0, count = 0;
	double sum = 0.0, average;

	while (i < Max && cin >> donation[i])
	{
		sum += donation[i];
		i++;
	}
	average = sum / i;
	for (int j = 0; j < i; j++)
	{
		if (donation[j] > average)
			count += 1;
	}
	cout << "average: " << average << endl;
	cout << "count: " << count << endl;
	return 0;
}

// 3
#include <iostream>
using namespace std;

void showmenu();

int main()
{	
	char choices;
	showmenu();
	while (cin.get(choices))
	{
		switch (choices)
		{
			case 'c':
				cout << "carnivore\n";
				break;
			case 'p':
				cout << "pianist\n";
				break;
			case 't':
				cout << "tree\n";
				break;
			case 'g':
				cout << "game\n";
				break;
			default:
				cout << "Please enter a c, p, t, or g: ";
		}
		cin.get();
	}
	return 0;
}

void showmenu()
{
	cout << "Plase enter one of the following choices:\n";
	cout << "c) carnivore		p) pianist\n";
	cout << "t) tree			g) game\n";
}

// 4
#include <iostream>

using namespace std;
const int usersize = 5;
const int strsize = 50;
void showmenu();

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

int main()
{
	bop bop_user[usersize] =
	{
		{"Wimp Macho", "Programmer", "MIPS", 0},
		{"Raki Rhodes", "Junior Programmer", "", 1},
		{"Celia Laiter", "", "MIPS", 2},
		{"Hoppy Hipman", "Analyst Trainee", "", 1},
		{"Pat Hand", "", "LOOPY", 2}
	};
	char choice;
	showmenu();
	cin.get(choice);
	while (choice != 'q')
	{
		switch (choice)
		{
			case 'a':
				for (int i = 0; i < usersize; i++)
					cout << bop_user[i].fullname << endl;
				break;
			case 'b':
				for (int i = 0; i < usersize; i++)
					cout << bop_user[i].title << endl;
				break;
			case 'c':
				for (int i = 0; i < usersize; i++)
					cout << bop_user[i].bopname << endl;
				break;
			case 'd':
				for (int i = 0; i < usersize; i++)
				{
					switch (bop_user[i].preference)
					{
						case 0:
							cout << bop_user[i].fullname << endl;
							break;
						case 1:
							cout << bop_user[i].title << endl;
							break;
						case 2:
							cout << bop_user[i].bopname << endl;
					}
				}
				break;
			default:
				cout << "Bye!" << endl;
				break;

		}
		cin.get();
		cout << "Next choice: ";
		cin.get(choice);
	}
	cout << "Bye!" << endl;
	return 0;
}

void showmenu()
{
	cout << "a. display by name		b. display by title\n";
	cout << "c. display by bopname		d. display by preference\n";
	cout << "q.quit\n";
}

// 5
#include <iostream>

int main()
{
	using namespace std;
	cout << "请输入工资： ";
	double wages;
	while (cin >> wages && wages >= 0)
	{
		if (wages <= 5000)
			cout << "税收：" << 0 << endl;
		else if (wages <= 15000)
			cout << "税收：" << (wages - 5000) * 0.10 << endl;
		else if (wages <= 35000)
			cout << "税收：" << 10000 * 0.10 + (wages - 15000) * 0.15 << endl;
		else
			cout << "税收：" << 10000 * 0.10 + 20000 * 0.15 + (wages - 35000) * 0.20 << endl;
		cout << "请输入工资： ";
	}
	return 0;
}

// 6
#include <iostream>
#include <string>
using namespace std;
void showGrandP();
void showP();

struct donateinfo
{
	string name;
	double money;
};

int main()
{
	cout << "请输入捐献者数目： ";
	int num, count = 0;
	cin >> num;
	donateinfo* pt = new donateinfo[num];
	donateinfo* gp = new donateinfo[num];
	donateinfo* p = new donateinfo[num];
	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << ":\n";
		cout << "name: ";
		cin.get();
		getline(cin, pt[i].name);
		cout << "money: ";
		cin >> pt[i].money;
		if (pt[i].money > 10000)
		{
			gp[count].name = pt[i].name;
			gp[count].money = pt[i].money;
			count++;
		}
		else
		{
			p[i - count].name = pt[i].name;
			p[i - count].money = pt[i].money;
		}
			

	}
	showGrandP();
	if (count == 0)
		cout << "\tNONE\n";
	else
	{
		for (int i = 0; i < count; i++)
			cout << gp[i].name << "\t\t" << gp[i].money << endl;
	}
	showP();
	if (num - count == 0)
		cout << "\tNONE\n";
	else
	{
		for (int i = 0; i < num - count; i++)
			cout << p[i].name << "\t\t" << p[i].money << endl;
	}
	return 0;
}

void showGrandP()
{
	cout << "   Grand Patrons\n";
	cout << "name\t\tmoney\n";
}

void showP()
{
	cout << "\tPatrons\n";
	cout << "name\t\tmoney\n";
}

// 7
#include <iostream>
#include <cctype>

using namespace std;
const int wordsize = 50;

int main()
{
	char word[wordsize];
	cout << "Enter words (q to quit)\n";
	int vowels, consonants, others;
	vowels = consonants = others = 0;
	while (cin >> word && strcmp(word, "q") != 0)
	{
		if (!isalpha(word[0]))
			others++;
		else
		{
			switch (word[0])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowels++;
					break;
				default:
					consonants++;
			}
		}
		
	}
	cout << vowels << " words beginning with vowels\n";
	cout << consonants << " words beginning with consonants\n";
	cout << others << " others";
	return 0;
}

// 8
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	using namespace std;
	const int SIZE = 60;
	char filename[SIZE];
	ifstream inFile;
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	int count = 0;
	char ch;

	inFile >> ch;
	while (inFile.good())
	{
		++count;
		inFile >> ch;
	}
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";

	cout << "The file " << filename << " contains "<< count << " characters." << endl;
	inFile.close();
	return 0;
}

// 9
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct donateinfo
{
	string name;
	double money;
};

int main()
{
	ifstream inFile;
	inFile.open("donation.txt");
	int num;
	inFile >> num;
	donateinfo* pt = new donateinfo[num];
	for (int i = 0; i < num && !inFile.eof(); i++)
	{	
		inFile.get();
		getline(inFile, pt[i].name);
		inFile >> pt[i].money;
	}
	bool empty = true;
	cout << "Grand Patrons\n";
	for (int i = 0; i < num; i++)
	{
		if (pt[i].money >= 10000)
		{
			cout << pt[i].name << ":" << pt[i].money << endl;
			empty = false;
		}
	}
	if (empty) cout << "NONE\n";
	empty = true;
	cout << "Patrons\n";
	for (int i = 0; i < num; i++)
	{
		if (pt[i].money < 10000)
		{
			cout << pt[i].name << ":" << pt[i].money << endl;
			empty = false;
		}
	}
	if (empty) cout << "NONE\n";
	inFile.close();
	return 0;
}

