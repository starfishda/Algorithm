#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct map {
	int x, y, w;
};

int n, m, k;
int a[1001][1001];
int dist[1001][1001][11];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs() {
	queue<map> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, w = q.front().w;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			return dist[x][y][w];
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nw = w + 1;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;

			if (dist[nx][ny][w]) 
				continue;
			if (a[nx][ny] == 0) {
				dist[nx][ny][w] = dist[x][y][w] + 1;
				q.push({ nx, ny, w });
			}

			if (a[nx][ny] == 1 && nw <= k) {
				// Break the wall
				dist[nx][ny][nw] = dist[x][y][w] + 1;
				q.push({ nx, ny, nw });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
			a[i][j] = temp[j] - '0';
	}
	cout << bfs();
	return 0;
}