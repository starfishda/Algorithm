#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m, k;
bool map[51][51];
bool check[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int front, int back) {
	check[front][back] = true;

	for (int i = 0; i < 4; i++) {
		int next_front = front + dy[i];
		int next_back = back + dx[i];

		if (next_front >= 0 && next_front < n && next_back >= 0 && next_back < m && !check[next_front][next_back] && map[next_front][next_back]) {
			dfs(next_front, next_back);
		}
	}
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(map, false, sizeof(map));
		memset(check, false, sizeof(check));
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			map[b][a] = true;
		}
		int count = 0;

		for (int k = 0; k < n; k++) {
			for (int t = 0; t < m; t++) {
				if (!check[k][t] && map[k][t]) {
					count++;
					dfs(k, t);
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}