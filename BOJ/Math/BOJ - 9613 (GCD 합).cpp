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
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		long long int sum = 0;
		cin >> n;

		int *arr = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}

		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum += gcd(arr[j], arr[k]);
			}
		}

		cout << sum << endl;
	}
	return 0;
}