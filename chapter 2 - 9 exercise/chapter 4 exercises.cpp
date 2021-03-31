// 1
#include <iostream>

int main()
{
	using namespace std;
	char first_name[20], last_name[20], grade;
	int age;
	cout << "What is your first name? ";
	cin.getline(first_name, 20);
	cout << "What is your last name? ";
	cin.getline(last_name, 20);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	grade += 1;
	cout << "What is your age? ";
	cin >> age;
	cout << "Name: " << last_name << ", " << first_name << endl;
	cout << "Grade: " << grade << endl;
	cout << "Age: " << age;
	return 0;
}

// 2
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string name, dessert;

	cout << "Enter your name:\n";
	getline(cin, name);
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}

// 3
#include <iostream>
#include <cstring>

int main()
{	
	using namespace std;
	char first_name[20], last_name[20], full_name[40];
	cout << "Enter your first name: ";
	cin.getline(first_name, 20);
	cout << "Enter your last name: ";
	cin.getline(last_name, 20);
	strcpy_s(full_name, last_name);
	strcat_s(full_name, ", ");
	strcat_s(full_name, first_name);
	cout << "Here's the information in a single string: " << full_name;
	return 0;
}

// 4
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string first_name, last_name, full_name;
	cout << "Enter your first name: ";
	getline(cin, first_name);
	cout << "Enter your last name: ";
	getline(cin, last_name);
	full_name = last_name + ", " + first_name;
	cout << "Here's the information in a single string: " << full_name;
	return 0;
}

//5
#include <iostream>

using namespace std;

struct CandyBar
{
	char band[20];
	float weight;
	unsigned int calorie;
};

int main()
{
	CandyBar snack = { "Mocha Munch", 2.3, 350 };
	cout << "My favorite CandyBar is " << snack.band << ".\n";
	cout << "And its weight is " << snack.weight << ", calorie is " << snack.calorie << ".\n";
	return 0;
}

// 6
#include <iostream>

using namespace std;

struct CandyBar
{
	char band[20];
	float weight;
	unsigned int calorie;
};

int main()
{
	CandyBar candy[3] = { {"A", 1.0, 1}, {"B", 2.0, 2}, {"C", 3.0, 3} };
	cout << "My first CandyBar is " << candy[0].band << ".\n";
	cout << "And its weight is " << candy[0].weight << ", calorie is " << candy[0].calorie << ".\n";
	return 0;
}

// 7
#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
	string company;
	float diameter;
	float weight;
};

int main()
{
	Pizza pizza;
	cout << "Enter the Pizza's information:" << endl;
	cout << "Pizza's Company:";
	getline(cin, pizza.company);
	cout << "Pizza's diameter(inchs): ";
	cin >> pizza.diameter;
	cout << "CandBar's weight(pounds): ";
	cin >> pizza.weight;
	cout << "The pizza is " << pizza.company << ".\n";
	cout << "And its diameter is " << pizza.diameter << " inch, weight is " << pizza.weight << "pound.";
	return 0;
}

// 8
#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
	string company;
	float diameter;
	float weight;
};

int main()
{
	Pizza* pt = new Pizza;
	cout << "Enter the Pizza's information:" << endl;
	cout << "Pizza's diameter(inchs): ";
	cin >> pt->diameter;
	cout << "Pizza's Company:";
	cin >> pt->company;
	cout << "CandBar's weight(pounds): ";
	cin >> pt->weight;
	cout << "The pizza is " << pt->company << ".\n";
	cout << "And its diameter is " << pt->diameter << " inch, weight is " << pt->weight << " pound.";
	delete pt;
	return 0;
}

// 9
#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
	char band[20];
	float weight;
	unsigned int calorie;
};

int main()
{
	CandyBar *pt = new CandyBar[3];
	strcpy_s(pt[0].band, "a");
	pt[0].weight = 2.3;
	pt[0].calorie = 8;
	cout << "My first CandyBar is " << pt[0].band << ".\n";
	cout << "And its weight is " << pt[0].weight << ", calorie is " << pt[0].calorie << ".\n";
	delete[] pt;
	return 0;
}

// 10
#include <iostream>
#include <array>

int main()
{
	using namespace std;
	array<float, 3> record_list;
	float average;
	cout << "Please input three record of 40 miles.\n";
	cout << "First recond:";
	cin >> record_list[0];
	cout << "Second recond:";
	cin >> record_list[1];
	cout << "Third recond:";
	cin >> record_list[2];
	average = (record_list[0] + record_list[1] + record_list[2]) / 3;
	cout << "You input:\n1." << record_list[0] << "\n2." << record_list[1] << "\n3." << record_list[2] << endl;
	cout << "Your average performance is " << average << ".";
	return 0;
}