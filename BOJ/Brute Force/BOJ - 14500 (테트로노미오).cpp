#include<iostream>
#include<algorithm>
using namespace std;
int block[500][500];

int main() {
	int ans = 0;
	int sum = 0;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> block[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//1. 네모모양
			if (i + 1 < n && j + 1 < m) {
				sum = block[i][j] + block[i + 1][j] + block[i][j + 1] + block[i + 1][j + 1];
				ans = max(ans, sum);
				sum = 0;
			}

			//2. 긴짝대기 - 세로 버전
			if (i + 3 < n) {
				sum = block[i][j] + block[i + 1][j] + block[i + 2][j] + block[i + 3][j];
				ans = max(ans, sum);
				sum = 0;
			}

			//2. 긴짝대기 - 가로 버전
			if (j + 3 < m) {
				sum = block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i][j + 3];
				ans = max(ans, sum);
				sum = 0;
			}

			if (i + 2 < n && j + 1 < m) {
				sum = block[i][j] + block[i + 1][j] + block[i + 2][j] + block[i + 2][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i + 1][j] + block[i + 2][j] + block[i][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i + 1][j + 1] + block[i + 2][j + 1] + block[i][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i + 2][j] + block[i + 1][j + 1] + block[i + 2][j + 1] + block[i][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i + 1][j] + block[i + 1][j + 1] + block[i + 2][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j + 1] + block[i + 1][j + 1] + block[i + 1][j] + block[i + 2][j];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i + 1][j] + block[i + 2][j] + block[i + 1][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i + 1][j] + block[i][j + 1] + block[i + 1][j + 1] + block[i + 2][j + 1];
				ans = max(ans, sum);
				sum = 0;
			}

			if (i + 1 < n && j + 2 < m) {
				sum = block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i + 1][j];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i + 1][j + 2];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i][j + 1] + block[i][j + 2] + block[i + 1][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i + 1][j] + block[i + 1][j + 1] + block[i + 1][j + 2] + block[i][j + 1];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i + 1][j] + block[i + 1][j + 1] + block[i + 1][j + 2] + block[i][j + 2];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i + 1][j] + block[i + 1][j + 1] + block[i + 1][j + 2] + block[i][j];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i + 1][j] + block[i + 1][j + 1] + block[i][j + 1] + block[i][j + 2];
				ans = max(ans, sum);
				sum = 0;

				sum = block[i][j] + block[i][j + 1] + block[i + 1][j + 1] + block[i + 1][j + 2];
				ans = max(ans, sum);
				sum = 0;
			}
		}
	}

	cout << ans;
	return 0;
}