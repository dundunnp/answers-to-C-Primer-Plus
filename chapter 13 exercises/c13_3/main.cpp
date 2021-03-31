#include "c13_3.h"
#include <iostream>
const int CLIENTS = 4;
using namespace std;

template<typename T> void input(T& t);

int main()
{
	ABC* p_clients[CLIENTS];
	char kind;


	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Select \n1) ABC \n2) baseDMA \n3) lacksDMA \n4) hasDMA \n";

		input(kind);
		while (kind != '1' && kind != '2' && kind != '3' && kind != '4')
		{
			cout << "Enter either 1 2 3 or 4 : ";
			input(kind);
		}

		if (kind == '1')
		{
			p_clients[i] = new ABC();
		}
		else if (kind == '2')
		{
			while (cin.get() != '\n')
				continue;
			char l[40];
			int r;
			cout << "Enter baseDMA's label: ";
			cin.getline(l, 40);
			cout << "Enter baseDMA's rating: ";
			input(r);
			p_clients[i] = new baseDMA(l, r);
		}
		else if (kind == '3')
		{
			while (cin.get() != '\n')
				continue;
			char l[40], c[40];
			int r;
			cout << "Enter lacksDMA's label: ";
			cin.getline(l, 40);
			cout << "Enter lacksDMA's color: ";
			cin.getline(c, 40);
			cout << "Enter lacksDMA's rating: ";
			input(r);
			p_clients[i] = new lacksDMA(c, l, r);
		}
		else
		{
			while (cin.get() != '\n')
				continue;
			char l[40], s[40];
			int r;
			cout << "Enter hasDMA's label: ";
			cin.getline(l, 40);
			cout << "Enter hasDMA's color: ";
			cin.getline(s, 40);
			cout << "Enter hasDMA's rating: ";
			input(r);
			p_clients[i] = new lacksDMA(s, l, r);
		}
		
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->View();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
		delete p_clients[i];

	cout << "Done.\n";
	return 0;
}

template<typename T> void input(T& t)
{
	while (!(cin >> t))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Error, please re-enter: ";
	}
}