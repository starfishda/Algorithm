#include <iostream>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		long long dp[101];
		dp[1] = dp[2] = dp[3] = 1;
		dp[4] = dp[5] = 2;

		if (n > 5) {
			for (int j = 6; j <= n; j++) {
				dp[j] = dp[j - 5] + dp[j - 1];
			}
		}
		cout << dp[n] << "\n";
	}
	return 0;
}