#include<iostream>

using namespace std;

int col[16];
int n;
int ans = 0;

bool possible(int i) {
	int k = 1;
	bool flag = true;

	while (k < i && flag) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
			flag = false;
		k++;
	}
	return flag;
}

void cal(int i) {
	if (possible(i)) {
		if (i == n)
			ans++;
		else {
			for (int j = 1; j <= n; j++) {
				col[i + 1] = j;
				cal(i + 1);
			}
		}
	}
}

int main() {
	cin >> n;

	cal(0);
	cout << ans;
	return 0;
}