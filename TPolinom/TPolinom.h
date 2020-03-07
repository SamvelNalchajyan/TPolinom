#pragma once
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
};