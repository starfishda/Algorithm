#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
char map[101][101];
bool visit[101][101];
int n;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs(int x, int y, bool check) {
	char cur = map[y][x];
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n){ 
				//RGB 다 구분
				if (!check) {
					if (!visit[next_y][next_x] && map[next_y][next_x] == cur) {
						visit[next_y][next_x] = true;
						q.push(make_pair(next_x, next_y));
					}
				}
				//적녹색약
				else {
					if (cur == 'R' || cur == 'G') {
						if (!visit[next_y][next_x] && (map[next_y][next_x] == 'R' || map[next_y][next_x] == 'G')) {
							visit[next_y][next_x] = true;
							q.push(make_pair(next_x, next_y));
						}
					}
					else {
						if (!visit[next_y][next_x] && map[next_y][next_x] == cur) {
							visit[next_y][next_x] = true;
							q.push(make_pair(next_x, next_y));
						}
					}
				}
			}
		}
	}
}

int main() {
	// 지도 맵 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				ans++;
				bfs(j, i, false);
			}
		}
	}

	cout << ans << " ";

	ans = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				ans++;
				bfs(j, i, true);
			}
		}
	}
	cout << ans;
	return 0;
}