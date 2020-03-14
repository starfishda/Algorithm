#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;

int main() {
	int n;

	cin >> n;

	int *dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		int a = sqrt(i);
		dp[i] = 1 + dp[i - 1];
		for (int j = 2; j <= a; j++) {
			dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
		}
	}

	cout << dp[n] << endl;
	return 0;
}