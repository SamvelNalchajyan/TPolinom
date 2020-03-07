#include <iostream>
#include <cstdlib>
#include <clocale>
#include "TPolinom.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*..........................................*/
	int mas[5][2];
	for (int i = 0; i < 5; i++)
	{
		mas[i][0] = i + 1;
	}
	for (int i = 0; i < 5; i++)
	{
		mas[i][1] = 156 + 10 * i;
	}
	TPolinom P(mas, 5);
	/*..........................................*/
	system("pause");
	return 0;
}