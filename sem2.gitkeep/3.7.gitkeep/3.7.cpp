#include <iostream>
using namespace std;

int main()
{
	const int n = 5;
	int arr[n] = { 22,45,670,12,7 };
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}

	}
	cout << max << endl;
	cout << min << endl;

	return 0;
}