#include <iostream>
#include "c10_5.h"
#include <cctype>
using namespace std;

int main()
{
	Stack st;
	customer cust;
	char select;
	double total_payment = 0.0;
	cout << "Select a (add), p (pop) or q(quit) :";
	while (cin.get(select) && tolower(select) != 'q')
	{
		while (cin.get() != '\n') continue;
		if (!isalpha(select))
		{
			cout << '\a';
			continue;
		}
		switch (select)
		{
		case 'a':
		case 'A':
			if (st.isfull())
				cout << "stack already full\n";
			else
			{
				cout << "Enter a customer's name: ";
				cin.getline(cust.fullname, 35);
				cout << "Enter a customer's payment: ";
				cin >> cust.payment;
				while (cin.get() != '\n') continue;
				st.push(cust);
				cout << "Item pushed.\n";
			}
			break;
		case 'p':
		case 'P':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(cust);
				total_payment += cust.payment;
				cout << "Pop Item's info:\nName: " << cust.fullname << endl;
				cout << "Payment: " << cust.payment << endl;
				cout << "Now, sum of paymenys: " << total_payment << endl;
			}
		}
		cout << "Select a (add), p (pop) or q(quit) :";
	}
	cout << "Bye.\n";
	return 0;
}