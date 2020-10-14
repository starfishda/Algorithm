#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int answer = 0;
int t[16];
int p[16];

void dfs(int day, int value, int last) {
	if (day > n + 1) {
		answer = max(answer, value - last);
		return;
	}
	else if (day == n + 1) {
		answer = max(answer, value);
		return;
	}

	for (int i = day; i <= n; i++) {
		dfs(i + t[i], value + p[i], p[i]);
	}
}

int main() {
	cin >> n;

	int a, b;
	for (int i = 1; i <= n; i++) 
		cin >> t[i] >> p[i];
	
	for (int i = 1; i <= n; i++) {
		dfs(i + t[i], p[i], p[i]);
	}
	cout << answer;
	return 0;
}