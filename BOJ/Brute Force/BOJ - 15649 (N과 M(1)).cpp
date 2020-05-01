#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
bool arr[10]; // �ʱⰪ�� false
int ans[10];

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
			ans[cnt] = i;
			recur(cnt + 1);
			arr[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = false;

	recur(0);

	return 0;
}