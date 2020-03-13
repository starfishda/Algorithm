#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int rgb[1001][3];
int dp[1001][3];

int main() {
	int n; 
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> rgb[i][j];
			if (i == 0)
				dp[0][j] = rgb[0][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][j] = min(dp[i - 1][1] + rgb[i][j], dp[i - 1][2] + rgb[i][j]);
			else if (j == 1)
				dp[i][j] = min(dp[i - 1][0] + rgb[i][j], dp[i - 1][2] + rgb[i][j]);
			else
				dp[i][j] = min(dp[i - 1][1] + rgb[i][j], dp[i - 1][0] + rgb[i][j]);
		}
	}

	std::cout << min(dp[n - 1][2], min(dp[n - 1][0], dp[n - 1][1])) << std::endl;
	return 0;
}