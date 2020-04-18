#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main() {
	string n;
	cin >> n;

	int dp[5001] = { 0, };
	int mod = 1000000;
	if (n[0] - '0' == 0) {
		cout << 0;
		return 0;
	}

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n.size(); i++) {
		if (n[i - 1] == '0' && n[i - 2] == '0') {
			cout << 0;
			return 0;
		}

		if (n[i - 1] != '0')
			dp[i] += dp[i - 1];
		if (n[i - 2] != '0') {
			int num = (n[i - 2] - '0') * 10 + n[i - 1] - '0';
			if (num <= 26)
				dp[i] += dp[i - 2];
		}
		dp[i] %= mod;
	}
	cout << dp[n.size()] << "\n";
	return 0;
}