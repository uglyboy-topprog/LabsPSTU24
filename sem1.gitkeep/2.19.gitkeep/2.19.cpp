#include <iostream>
using namespace std;
int main()
{
	int n;
	int s = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			s -= 1;
		}
		else
		{
			s += 1;
		}
	}
	cout << s << endl;
}