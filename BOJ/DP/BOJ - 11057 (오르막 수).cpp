#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int dp[1001][10] = { 0, };

int main() {
	int n; 
	std::cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for(int k = 0;k <= j;k++) 
				dp[i][j] += dp[i - 1][k];
			dp[i][j] %= 10007;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % 10007;
	}
	
	std::cout << sum % 10007 << std::endl;
	return 0;
}