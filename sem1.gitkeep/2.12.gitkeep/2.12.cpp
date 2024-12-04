#include <iostream>
using namespace std;
int main()
{	
	setlocale(LC_ALL, "RUS");
	int n, b, max_0 = -10000, min = 10000;
	cout << "Введите длину последовательности:" << endl;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{	
		cout << "Введите - " << n << " - элемента(ов) последовательности:" << endl;
		cin >> b;
		if (b >= max_0) 
		{
			max_0 = b;
		}
		if (b <= min) 
		{
			min = b;
		}
	}
	cout << "Сумма минимального и максимального значения:" << endl;
	cout << max_0 + min << endl;
}