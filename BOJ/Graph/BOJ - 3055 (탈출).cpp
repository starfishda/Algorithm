#include <iostream>
#include <queue>
#include <string>

using namespace std;

char map[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };
bool visit[51][51];
int r, c;
int end_x, end_y;

queue<pair<int, int>> water;
queue<pair<int, int>> go;

int bfs() {
	int ans = 0;
	while (!go.empty()) {
		ans++;
		int size = water.size();
		while (size--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == 'D' || map[nx][ny] == '*') continue;
				water.push(make_pair(nx, ny));
				map[nx][ny] = '*';
			}
		}

		size = go.size();
		while (size--) {
			int x = go.front().first;
			int y = go.front().second;
			go.pop();

			visit[x][y] = true;
			if (x == end_x && y == end_y)
				return ans - 1;


			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (map[nx][ny] == 'X' || map[nx][ny] == '*' || visit[nx][ny]) continue;
				visit[nx][ny] = true;
				go.push(make_pair(nx, ny));
			}
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S')
				go.push(make_pair(i, j));
			if (map[i][j] == 'D') {
				end_x = i;
				end_y = j;
			}
			if (map[i][j] == '*')
				water.push(make_pair(i, j));
		}
	}
	int ans = bfs();

	if (ans == -1)
		cout << "KAKTUS";
	else
		cout << ans;
}