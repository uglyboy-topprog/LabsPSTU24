#include <iostream>
using namespace std;
int main() {
	int a, b, t;
	int* aptr;
	int* bptr;

	cin >> a;
	aptr = &a;
	t = *aptr;
	cin >> b;
	bptr = &b;
	*aptr = *bptr;
	*bptr = t;



	cout << *aptr << *bptr << endl;
	return 0;

}