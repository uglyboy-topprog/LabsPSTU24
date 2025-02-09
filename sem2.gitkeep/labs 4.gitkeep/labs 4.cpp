#include <iostream>
using namespace std;

int main()
{
	int n;

	int a[100]; // создаем массив

	cin >> n; // размерность массива

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100; // заполняем массив случайными числами
		cout << a[i] << " "; // распечатываем массив
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
	}

	for (int i = n; i < n + 3; i++)
	{
		a[i] = rand() % 100;
	}
	n += 3;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	return 0;

}