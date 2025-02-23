#include <iostream>
using namespace std;

int main()
{
	const int n = 5;
	int m = n;
	int arr[n] = { 1,14,3,8,47 };
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			for (int j = n - 1; j < i - 1; j--)
			{
				arr[j + 1] == arr[j];
			}
		}
		arr[i] = -1;
		i++;
		m++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
	return 0;
}