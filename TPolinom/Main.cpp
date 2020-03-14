#include <iostream>
#include <cstdlib>
#include <clocale>
#include "TPolinom.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*..........................................*/
	/*
	int mas[2][2];
	mas[0][0] = 5;
	mas[1][0] = -3;
	mas[0][1] = 563;
	mas[1][1] = 267;
	TPolinom P(mas, 1);
	
	TMonom m1;
	m1.coeff = 5.5;
	m1.px = 8;
	m1.py = 6;
	m1.pz = 13;
	P += m1;
	TPolinom Q = P;
	Q += P;
	*/
	TPolinom P, Q;
	cout << "������� P" << endl;
	cin >> P;
	cout << "������� Q" << endl;
	cin >> Q;
	cout << endl;
	cout << "P = " << P << endl;
	cout << "Q = " << Q << endl;
	TPolinom T = P + Q;
	cout << "P + Q = " << T << endl;
	/*..........................................*/
	system("pause");
	return 0;
}