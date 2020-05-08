#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
int ans[10];
int num[10];

void recur(int tmp, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = tmp; i <= n; i++) {
		ans[cnt] = num[i];
		recur(i, cnt + 1);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + n + 1);

	recur(1, 0);

	return 0;
}