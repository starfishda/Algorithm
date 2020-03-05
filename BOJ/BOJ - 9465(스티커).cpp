#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int dp[2][100001];
int sti[2][100001];

int main() {
	int T; //number of Testcase
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		std::cin >> n; // Type col

		//Type sticker reward
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				std::cin >> sti[j][k];
			}
		} 

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = sti[0][1];
		dp[1][1] = sti[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + sti[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + sti[1][j];
		}

		std::cout << max(dp[0][n], dp[1][n]) << std::endl;
	}
	return 0;
}