//Решите квадратное уравнение вида a ∗ x2 + b ∗ x + c = 0. Коэффициенты уравнения вводятся с клавиатуры.
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int a, b, c;
	double x1, x2;
	cin >> a;
	cin >> b;
	cin >> c;
	if (b * b - 4 * a * c < 0)
	{
		cout << "error" << endl;
	}
	else if (b * b - 4 * a * c >= 0)
	{
		x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	}
	cout << "Превый корень уравнения:" << x1 << endl;
	cout << "Второй корень уравнения:" << x2 << endl;
}