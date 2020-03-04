#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n;
	std::cin >> n; // number of wine

	int *wine = new int[n];
	int *dp = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> wine[i];
	}

	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];

	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]));
	}

	std::cout << dp[n - 1] << std::endl;
	return 0;
}