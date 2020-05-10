#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
bool arr[10];
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

	bool check[10002] = { 0, };
	for (int i = 1; i <= n; i++) {
		if (!check[num[i]] && !arr[i]) {
			arr[i] = true;
			ans[cnt] = num[i];
			check[num[i]] = true;
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