#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;


int dp[501][501];

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; i <= i; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] += dp[i - 1][j];
			else if (j == n)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);

		}
	}

	int sum = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[n][i] > sum)
			sum = dp[n][i];
	}

	cout << sum << endl;
	return 0;
}