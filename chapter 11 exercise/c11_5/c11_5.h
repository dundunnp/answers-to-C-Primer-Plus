#pragma once
#ifndef C11_5_H_
#define C11_5_H_

class Stonewt
{
public:
	enum Style { STONE, POUNDS, FLOATPOUNDS };
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	Style style;

public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();

	void Set_Style(Style m);
	Stonewt operator+(const Stonewt& s) const;
	Stonewt operator-(const Stonewt& s) const;
	Stonewt operator*(double n) const;
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& s);

};
#endif