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
	cout << "¬ведите P" << endl;
	cin >> P;
	cout << "¬ведите Q" << endl;
	cin >> Q;
	cout << endl;
	cout << "P = " << P << endl;
	cout << "Q = " << Q << endl;
	TPolinom T = P + Q;
	cout << "P + Q = " << T << endl;
	
	/*
	TMonom m1, m2;
	m1.coeff = 9.9;
	m1.px = 6;
	m1.py = 12;
	m1.pz = 2;
	m2.coeff = 8;
	m2.px = 8;
	m2.py = 0;
	m2.pz = 11;
	TPolinom p;
	cout << "¬ведите p" << endl;
	cin >> p;
	cout << p << endl;
	p *= m1;
	p += m2;
	p *= m2;
	p += m1;
	cout << p << endl;
	*/

	/*..........................................*/
	system("pause");
	return 0;
}