#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, m;
bool arr[10]; // 초기값은 false

void recur(int tmp, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (arr[i])
				cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = tmp; i <= n; i++) {
		if (!arr[i]) {
			arr[i] = true;
			recur(i, cnt + 1);
			arr[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = false;

	recur(1, 0);

	return 0;
}