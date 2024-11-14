#include <iostream>
using namespace std;
int main() {
	int q;
	int sum = 0;
	if (q <= 0) {
		cout << "error" << endl;
	}
	else {
		for (int i = 1; i <= q; i++);
		{
			sum += 1;
		}
	}
	cout << sum << endl;
	return 0;
}