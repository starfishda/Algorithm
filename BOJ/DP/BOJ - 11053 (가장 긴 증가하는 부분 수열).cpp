#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n;
	int dp[1000] = {};
	int arr[1000] = {};
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		sum = max(sum, dp[i]);
	}

	cout << sum << endl;
	return 0;
}