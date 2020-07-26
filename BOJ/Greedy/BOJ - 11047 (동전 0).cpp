#include<iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int *coin = new int[n];
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += k / coin[i];
		k %= coin[i];
	}

	cout << ans;
	return 0;
}