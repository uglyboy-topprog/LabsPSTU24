#include <iostream>
using namespace std;
int main() {
	int c;
	float a, b;
	cin >> a >> b >> c;
	switch (c) 
	{
	case 1:
	{
		cout << a + b << endl; 
		break;
	}
	case 2:
	{
		cout << a - b << endl; 
		break;
	}
	case 3:
	{
		cout << a * b << endl; 
		break;
	}
	case 4:
	{
		if (b != 0) 
		{
			cout << a / b << endl;
		}
		else
		{
			cout << "division by 0" << endl;
		}
		break;
	}
	default:
	{
		cout << "-vibe" << endl;
	}
	}
	return 0;
}
