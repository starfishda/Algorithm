#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int x, y;
int map[1000][1000];
queue<pair<int, int>> q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < x && ny >= 0 && ny < y&& map[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				map[nx][ny] = map[cx][cy] + 1;
			}
		}
	}
}

int main() {
	cin >> y >> x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	bfs();
	int answer = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}

			if (map[i][j] > answer)
				answer = map[i][j];
		}
	}
	cout << answer - 1;
	return 0;
}