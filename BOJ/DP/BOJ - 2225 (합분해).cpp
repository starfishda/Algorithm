#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;

int main() {
	int n, k;

	cin >> n;
	cin >> k;

	long dp[201][201] = { 0, };

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 1000000000;
		}
	}

	printf("%d", dp[k][n]);
	return 0;
}