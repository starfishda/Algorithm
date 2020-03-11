#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int T;
	std::cin >> T; //�׽�Ʈ ���̽� ���� �Է�

	int n;

	for (int i = 0; i < T; i++) {
		std::cin >>  n; // 1,2,3���� ǥ���� �� ����
		
		int *dp = new int[n];
		dp[0] = 1;
		dp[1] = 2;
		dp[2] = 4;

		for (int j = 3; j < n; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		std::cout << dp[n - 1] << std::endl;
	}
	return 0;
}