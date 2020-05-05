#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
bool arr[10]; // 초기값은 false
int ans[10];
int num[10];

void recur(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			arr[i] = true;
			ans[cnt] = num[i];
			recur(cnt + 1);
			arr[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = false;

	for (int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + n + 1);

	recur(0);

	return 0;
}