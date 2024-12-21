// f'(x)=0.75x**2 +1
// f''(x)=1.5x
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float x, x1;

	x = 2;
	x1 = 0;
	double eps = 0.000001;

	while (abs(x - x1) > eps)
	{
		x1 = x;
		x = x1 - (0.25 * (pow(x1, 3)) + x1 - 1.2502) / (0.75 * (pow(x1, 3)) + 1);
	}
	cout << x << endl;
	return 0;
}