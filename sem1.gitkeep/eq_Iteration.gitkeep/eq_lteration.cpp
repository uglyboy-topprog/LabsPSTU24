//f(x) = 0.25*x**3 + x - 1.2502
// f'(x)=0.75*x**2 + 1 
// [0,2] - a и b
// fi(x) = x + λ(x**3 - x - 1)
//  r = max(|f'(a)|, |f'(b)|) = 4
//  -1/r < λ < 0
//	λ = -1/4 = -0.25	
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float x, x1;
	double eps = 0.00001;
	double lambda = -0.25;

	x = 2;
	x1 = 0;

	while (abs(x - x1) > eps)
	{
		x1 = x;
		x = lambda * (pow(x1, 3) - x1 - 1) + x1;
	}
	cout << x << endl;
	return 0;
}