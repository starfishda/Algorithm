#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
bool arr[10]; // 초기값은 false
int ans[10];

void recur(int tmp, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		ans[cnt] = i;
		recur(i, cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = false;

	recur(1, 0);

	return 0;
}