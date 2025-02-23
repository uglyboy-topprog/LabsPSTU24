#include <iostream>
using namespace std;

int main()
{
	const int n = 5;
	bool flag = true;
	int arr[n] = { 3,2,5,7,8 };

	for (int i = n - 1; i > 0; i--)
	{
		if (arr[i] < arr[i - 1])
		{
			flag = false;
		}
	}

	if (flag)
	{
		cout << "yep" << endl;
	}
	else
	{
		cout << "nono" << endl;
	}
	return 0;
}