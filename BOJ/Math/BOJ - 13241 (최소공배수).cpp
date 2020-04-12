#include<iostream>
#include<algorithm>
using namespace std;

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		long long int s = a % b;
		a = b;
		b = s;
	}
	return a;
}

long long int lcm(long long int a, long long int b, long long int gcd) {
	return a * b / gcd;
}

int main() {
	long long int a, b;
	cin >> a >> b;

	long long int gcd_num = gcd(a, b);
	cout << lcm(a, b, gcd_num) << endl;

	return 0;
}