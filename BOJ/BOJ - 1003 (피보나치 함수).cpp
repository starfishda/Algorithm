#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int dp[41];

int fibonacci(int n) {
	if (n == 0) {
		dp[0] = 0;
		return 0;
	}
	else if (n == 1) {
		dp[1] = 1;
		return 1;
	}

	if (dp[n] != 0)
		return dp[n];
	else {
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int T; 
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		std::cin >> n;

		if (n == 0)
			std::cout << 1 << " " << 0 << std::endl;
		else if (n == 1)
			std::cout << 0 << " " << 1 << std::endl;
		else {
			fibonacci(n);
			std::cout << dp[n - 1] << " " << dp[n] << std::endl;
		}
	}
	return 0;
}