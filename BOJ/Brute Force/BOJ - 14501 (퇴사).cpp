#include<iostream>
#include<algorithm>

int n;
int time[16];
int pay[16];
bool print = false;
int ans = 0;
using namespace std;

void recur(int date, int sum, int count) {
	if (date == n + 1) {
		ans = max(ans, sum);
		return;
	}

	else if (date > n + 1) {
		ans = max(ans, sum - count);
		return;
	}

	for (int i = date + time[date]; i <= n + time[date]; i++) {
		recur(i, sum + pay[date], pay[date]);
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
	}

	for (int i = 1; i <= n; i++) {
		recur(i, 0, 0);
	}

	cout << ans;
	return 0;
}