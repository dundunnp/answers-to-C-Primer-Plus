#include "c12_4.h"
#include <cctype>

int main()
{
	using std::cout;
	using std::cin;

	Stack st1(3);
	char ch;
	Item po;
	cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n') continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st1.isfull())
				cout << "stack already full\n";
			else
				st1.push(po);
			cout << st1;
			break;
		case 'p':
		case 'P':
			if (st1.isempty())
				cout << "stack already empty\n";
			else
			{
				st1.pop(po);
				cout << "PO #" << po << " popped\n";
			}
			cout << st1;
			break;
		}
		cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
	}
	Stack st2 = st1;
	st2.push(3);
	cout << st2;
	Stack st3(st1);
	st3.push(4);
	cout << st3;
	cout << "Bye\n";
	return 0;
}