#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n;
	std::cin >> n; // number of stairs

	int *stair = new int[n];
	int *dp = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> stair[i]; // type point of each stair
	}

	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
	}
	std::cout << dp[n - 1] << std::endl;
	return 0;
}