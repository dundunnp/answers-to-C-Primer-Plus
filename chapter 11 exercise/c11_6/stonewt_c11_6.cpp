#include <iostream>
#include "c11_6.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	style = POUNDS;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	style = FLOATPOUNDS;
}

Stonewt::Stonewt()
{
	stone = pds_left = pounds = 0;
	style = STONE;
}

void Stonewt::Set_Style(Style m)
{
	style = m;
}

Stonewt Stonewt::operator+(const Stonewt& s) const
{
	Stonewt sum;
	sum.pounds = pounds + s.pounds;
	sum.stone = sum.pounds / Lbs_per_stn;
	sum.pds_left = int(sum.pounds) % Lbs_per_stn + sum.pounds - int(sum.pounds);
	sum.style = this->style;
	return sum;
}

Stonewt Stonewt::operator-(const Stonewt& s) const
{
	Stonewt diff;
	diff.pounds = pounds - s.pounds;
	diff.stone = diff.pounds / Lbs_per_stn;
	diff.pds_left = int(diff.pounds) % Lbs_per_stn + diff.pounds - int(diff.pounds);
	diff.style = this->style;
	return diff;
}

Stonewt Stonewt::operator*(double n) const
{
	Stonewt mul;
	mul.pounds = pounds * n;
	mul.stone = mul.pounds / Lbs_per_stn;
	mul.pds_left = int(mul.pounds) % Lbs_per_stn + mul.pounds - int(mul.pounds);
	mul.style = this->style;
	return mul;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& s)
{
	if (s.style == Stonewt::STONE)
	{
		double st = s.stone + s.pds_left / Stonewt::Lbs_per_stn;
		os << st << " stone\n";
	}
	else if (s.style == Stonewt::POUNDS)
		os << s.pounds << " pounds\n";
	else
		os << s.stone << " stone, " << s.pds_left << " pounds\n";
	return os;
}

bool Stonewt::operator<(const Stonewt& s) const
{
	return pounds < s.pounds;
}

bool Stonewt::operator<=(const Stonewt& s) const
{
	return pounds <= s.pounds;
}

bool Stonewt::operator>(const Stonewt& s) const
{
	return pounds > s.pounds;
}

bool Stonewt::operator>=(const Stonewt& s) const
{
	return pounds >= s.pounds;
}

bool Stonewt::operator==(const Stonewt& s) const
{
	return pounds == s.pounds;
}

bool Stonewt::operator!=(const Stonewt& s) const
{
	return pounds != s.pounds;
}