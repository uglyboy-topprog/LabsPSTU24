#include <iostream>
using namespace std;
int main() {
	float a, b, s1, s2;
	float* aptr;
	float* bptr;

	cin >> a;
	aptr = &a;

	cin >> b;
	bptr = &b;
	s1 = *aptr;
	s2 = *bptr;

	cout << s1 + s2 << endl;
	return 0;




}