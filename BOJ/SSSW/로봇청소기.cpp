#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[50][50];
int answer = 0;

// 바라보는 방향
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

// 바라보는 방향에 따른 후진
int back_dx[4] = { 1,0,-1,0 };
int back_dy[4] = { 0,-1,0,1 };

int direct[4] = { 3,0,1,2 };

void dfs(int x, int y, int d) {
	if (map[x][y] == 0) {
		answer++;
		map[x][y] = 2;
	}

	if (map[x][y] == 1)
		return;

	for (int i = 0; i < 4; i++) {
		int nd = direct[d];
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if (map[nx][ny] == 0) {
			dfs(nx, ny, nd);
			return;
		}
		else
			d = nd;
	}

	int nx = x + back_dx[d];
	int ny = y + back_dy[d];
	dfs(nx, ny, d);
}

int main() {
	int n, m;
	int x, y, dir;

	cin >> n >> m;
	cin >> x >> y >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(x, y, dir);
	cout << answer;
	return 0;
}