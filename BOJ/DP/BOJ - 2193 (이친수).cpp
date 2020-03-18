#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n; 
	std::cin >> n;

	long long int *dp = new long long int[n];

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[n - 1] << std::endl;
	return 0;
}