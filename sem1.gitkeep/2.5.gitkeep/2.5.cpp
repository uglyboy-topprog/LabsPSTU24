﻿#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n <= 2)
		cout << "error" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	return 0;

}
