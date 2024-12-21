#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	float a, b, c;
	float fA, fB, fC;
	double eps = 0.000001;

	a = 0;
	b = 1;
	
	while (b - a > eps)
	{
		c = (a + b) / 2;

		fA = (abs(1 - 0.4 * pow(a, 2)) - asin(a));
		fB = (abs(1 - 0.4 * pow(b, 2)) - asin(b));
		fC = (abs(1 - 0.4 * pow(c, 2)) - asin(c));

		if (fA * fC < 0) { b = c; }
		else if (fC * fB < 0) { a = c; }
		else { cout << "Что-то пошло не так!" << endl; }

	}
	cout << "Корни: " << a << "; " << b << endl;
	return 0;
}
