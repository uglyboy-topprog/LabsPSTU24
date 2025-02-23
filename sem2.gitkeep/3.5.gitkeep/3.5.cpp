#include <iostream>
using namespace std;

int main()
{
	const int n = 5;
	int arr[n] = { 1,2,3,4,5 };
	int max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	cout << max << endl;
	return 0;
}