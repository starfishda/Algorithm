#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int n, s;
	cin >> n;
	cin >> s;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;

		k -= s;
		if (k < 0)
			k = -k;
		arr[i] = k;
	}

	int gcd_num = arr[0];
	for (int i = 1; i < n; i++) {
		gcd_num = gcd(gcd_num, arr[i]);
	}

	cout << gcd_num << "\n";

	return 0;
}