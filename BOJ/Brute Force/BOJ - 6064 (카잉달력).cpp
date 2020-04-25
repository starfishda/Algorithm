#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int s = a % b;
		a = b;
		b = s;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int check = lcm(m, n);
		while (x <= check) {
			if (x % n == y % n) {
				break;
			}
			else 
				x += m;
		}

		if (x > check)
			cout << -1 << "\n";
		else
			cout << x << "\n";
	}
	return 0;
}