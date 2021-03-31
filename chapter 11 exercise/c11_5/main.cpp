#include <iostream>
#include "c11_5.h"

int main()
{
	using std::endl;
	using std::cout;
	Stonewt incognito = 275;
	cout << "incognito: " << incognito << endl;
	Stonewt wolfe(285.7);
	cout << "wolfe: " << wolfe << endl;
	Stonewt taft(21, 8);
	cout << "taft: " << taft << endl;

	incognito = 276.8;
	cout << "incognito: " << incognito << endl;
	cout << "incognito: " << incognito << endl;

	cout << "wolfe: " << wolfe * 2.3 << endl;
	taft = incognito + wolfe + 200;
	cout << "taft: " << taft << endl;
	wolfe.Set_Style(Stonewt::FLOATPOUNDS);
	wolfe = wolfe * 2.3;
	cout << "wolfe: " << wolfe * 2.3 << endl;
	return 0;

}