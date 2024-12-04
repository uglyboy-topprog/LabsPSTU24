#include <iostream>
using namespace std;
int main()
{
	int n;
	int result = 0;
	cin >> n;
	while (n > 0)
	{
		result = result * 10 + n % 10;
		n /= 10;
	}
	cout << result << endl;
}