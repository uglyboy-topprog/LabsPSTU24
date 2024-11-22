#include <iostream>
using namespace std;
int main() {
	int a, b, s1, s2;
	int* aptr;
	int* bptr;

	cin >> a;
	aptr = &a;

	cin >> b;
	bptr = &b;
	s1 = *aptr;
	s2 = *bptr;

	cout << s1 + s2 << endl;
	return 0;




}