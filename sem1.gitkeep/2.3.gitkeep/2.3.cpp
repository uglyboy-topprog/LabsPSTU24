#include <iostream>
using namespace std;
int main() {
	int n;
	int s = 0, t;
	cin >> n;
	for (int i = 1 ; i <= n; i++) {
		t = 1;
		for (int j = 1; j <= 2 * i; j++) {
			t *= j;
		}
	}s += t;
	cout << s << endl;
}