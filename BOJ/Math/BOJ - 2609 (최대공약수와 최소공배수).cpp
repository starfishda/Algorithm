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

int lcm(int a, int b, int gcd) {
	return a * b / gcd;
}

int main() {
	int a, b;
	cin >> a >> b;

	int gcd_num = gcd(a, b);
	cout << gcd_num << endl;
	cout << lcm(a, b, gcd_num) << endl;

	return 0;
}