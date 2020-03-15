#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n;

	cin >> n;

	int *dp = new int[n];
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int sum = dp[0];
	
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		sum = max(sum, dp[i]);
	}

	cout << sum << endl;
	return 0;
}