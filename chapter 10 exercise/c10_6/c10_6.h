#pragma once
#ifndef C10_6_H_
#define C10_6_H_

class Move
{
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move& m);
	void reset(double a = 0, double b = 0);
};
#endif
