#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int T;
	std::cin >> T; //테스트 케이스 개수 입력

	int n;

	for (int i = 0; i < T; i++) {
		std::cin >>  n; // 1,2,3으로 표현해 줄 숫자
		
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