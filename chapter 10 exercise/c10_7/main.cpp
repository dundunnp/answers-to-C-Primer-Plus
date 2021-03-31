#include "c10_7.h"

int main()
{
	Plorg p1, p2("xiazizhun", 15);
	p1.show();
	p2.show();
	p1.setCI(12);
	p1.show();
	p2.setCI();
	p2.show();
}