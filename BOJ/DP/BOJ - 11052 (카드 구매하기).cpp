#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n; 
	std::cin >> n;

	int *card = new int[n + 1];
	int *dp = new int[n + 1];
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		std::cin >> card[i];
		dp[i] = 0;
	}

	dp[1] = card[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	std::cout << dp[n] << std::endl;
	return 0;
}