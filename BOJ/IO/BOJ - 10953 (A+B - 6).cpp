#include <iostream>
using namespace std;

int main() {
	int t;
	int a, b;
	char c;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> c >> b;
		cout << a + b << "\n";
	}
	return 0;
}