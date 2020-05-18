#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
int ans[15];
int num[15];

void recur(int tmp, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = tmp; i <= n; i++) {
		ans[cnt] = num[i];
		recur(i + 1, cnt + 1);
	}
}

int main() {
	cin >> n;
	while (n != 0) {
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
		}
		recur(1, 0);
		cout << "\n";
		cin >> n;
	}

	return 0;
}