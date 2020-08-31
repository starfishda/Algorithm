#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int w, h;
char map[100][100];
int visit[100][100];
int b_x, b_y;
pair<int, int> start, end_;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int a, int b) {
	queue<pair<pair<int, int>, pair<int, int>>> q;

	for (int i = 0; i < 4; i++) {
		q.push(make_pair(make_pair(a, b), make_pair(i, 0)));
	}
	visit[a][b] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int n = cnt;

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;

			if (map[nx][ny] == '*')
				continue;

			if (dir != i)
				n++;

			if (visit[nx][ny] >= n) {
				visit[nx][ny] == n;
				q.push(make_pair(make_pair(nx, ny), make_pair(i, n)));
			}
		}
	}
	return visit[end_.first][end_.second];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> w >> h;
	int temp = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (temp == 0) {
					start.first = i;
					start.second = j;
					temp++;
				}
				else {
					end_.first = i;
					end_.second = j;
				}
			}
			visit[i][j] = 9999999;
		}
	}
	
	int ans = bfs(start.first, start.second);
	cout << ans;
	return 0;
}