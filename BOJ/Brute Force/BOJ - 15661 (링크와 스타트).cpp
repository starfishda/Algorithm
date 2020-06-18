#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
bool arr[20] = { false, }; // 초기값은 false
int value[20][20];
int ans[10];
int ans2[10];
int min_value = 0;

void recur(int m, int index, int cnt) {
	if (cnt == m) {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (!arr[i]) {
				ans2[k] = i;
				k++;
			}
		}

		int start = 0;
		int link = 0;

		if (m == 1)
			start = 0;
		else {
			for (int i = 0; i < m - 1; i++) {
				for (int j = i + 1; j < m; j++) {
					start += value[ans[i]][ans[j]] + value[ans[j]][ans[i]];
				}
			}
		}

		if (k == 1)
			link = 0;
		else {
			for (int i = 0; i < k - 1; i++) {
				for (int j = i + 1; j < k; j++) {
					link += value[ans2[i]][ans2[j]] + value[ans2[j]][ans2[i]];
				}
			}
		}

		min_value = min(min_value, abs(start - link));
		return;
	}

	for (int i = index; i < n; i++) {
		if (!arr[i]) {
			arr[i] = true;
			ans[cnt] = i;
			recur(m, i + 1, cnt + 1);
			arr[i] = false;
		}
	}
}

int main() {
	cin >> n;

	// 값 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> value[i][j];
			min_value += value[i][j];
		}
	}

	for (int i = 1; i <= n - 1; i++)
		recur(i, 0, 0);
	cout << min_value;
	return 0;
}