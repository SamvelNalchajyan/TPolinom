#pragma once
#include <iostream>
#include "THeadList.h"

struct TMonom
{
	double coeff;
	int px;
	int py;
	int pz;
	TMonom();
	bool operator<(TMonom mon);
	bool operator<=(TMonom mon);
	bool operator>(TMonom mon);
	bool operator>=(TMonom mon);
	bool operator==(TMonom mon);
	bool operator!=(TMonom mon);
};

class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& p);
	TPolinom(int arr[][2], int size);
	
	TPolinom& operator=(TPolinom& p);
	TPolinom& operator+=(TMonom& mon);
	TPolinom operator+(TMonom& mon);
	TPolinom& operator*=(TMonom& mon);
	TPolinom operator*(TMonom& mon);
	TPolinom& operator+=(TPolinom& p);
	TPolinom operator+(TPolinom& p);
	bool operator==(TPolinom& p);
	bool operator!=(TPolinom& p);
	TPolinom& operator*=(double a);
	TPolinom operator*(double a);
	
	friend std::istream& operator>>(std::istream& in, TPolinom& P)
	{
		
		TMonom mon;
		double coeff = 1;
		int px = 0, py = 0, pz = 0;
		while (coeff != 0)
		{
			in >> coeff >> px >> py >> pz;
			mon.coeff = coeff;
			mon.px = px;
			mon.py = py;
			mon.pz = pz;
			P += mon;
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, TPolinom& P)
	{
		for (P.Reset(); !P.IsEnd(); P.GoNext())
		{
			out << '(' << P.pCurr->val.coeff << ')' << "x^" << P.pCurr->val.px << "y^" << P.pCurr->val.py << "z^" << P.pCurr->val.pz << "  ";
		}
		return out;
	}
};