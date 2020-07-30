#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
int map[9][9];
int c_map[9][9];
int temp[9][9];
int n, m;
int ans = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			c_map[i][j] = map[i][j];
	}
}

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (temp[i][j] == 2)
				q.push(make_pair(i, j));
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a >= 0 && b >= 0 && a < n && b < m && temp[a][b] == 0) {
				temp[a][b] = 2;
				q.push(make_pair(a, b));
			}
		}
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (temp[i][j] == 0)
				num++;
	}
	ans = max(num, ans);
}

void wall(int count) {
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				temp[i][j] = c_map[i][j];
		}

		bfs();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0) {
				c_map[i][j] = 1;
				wall(count + 1);
				c_map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				copy();
				c_map[i][j] = 1;
				wall(1);
				c_map[i][j] = 0;
			}
		}
	}

	cout << ans;
	return 0;
}