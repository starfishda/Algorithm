#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int tri[501][501];
int dp[501][501];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tri[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}

	cout << ans;
	return 0;
}