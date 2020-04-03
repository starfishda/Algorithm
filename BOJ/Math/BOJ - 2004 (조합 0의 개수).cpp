#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int two = 0;
	for (long long i = 2; i <= n; i *= 2)
		two = two + (n / i);

	for (long long i = 2; i <= m; i *= 2)
		two = two - (m / i);

	for (long long i = 2; i <= (n - m); i *= 2)
		two = two - ((n - m) / i);

	int five = 0;
	for (long long i = 5; i <= n; i *= 5)
		five = five + (n / i);

	for (long long i = 5; i <= m; i *= 5)
		five = five - (m / i);

	for (long long i = 5; i <= (n - m); i *= 5)
		five = five - ((n - m) / i);

	cout << min(two, five) << "\n";
	return 0;
}