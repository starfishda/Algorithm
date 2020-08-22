#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int result = 0;
int eat_count = 0;
int b_size = 2;
int map[21][21];
int visit[21][21];
int b_x, b_y;
vector <pair <pair<int, int>, int>> eat;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int x, int y) {
	int dis = 999999;
	eat.clear();
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int a = q.front().first; 
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i]; 
			int ny = b + dy[i];

			if (0 > nx || n <= nx || 0 > ny || n <= ny) 
				continue;

			if (visit[nx][ny] == 0 && b_size >= map[nx][ny]) { 
				visit[nx][ny] = visit[a][b] + 1;
				if (map[nx][ny] > 0 && map[nx][ny] < b_size) {
					if (dis >= visit[nx][ny]) {
						dis = visit[nx][ny];
						eat.push_back(make_pair(make_pair(dis, nx), ny));
					}
				}
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				map[i][j] = 0;
				b_x = i; 
				b_y = j;
			}
		}
	}

	while (1) {
		bfs(b_x, b_y);

		if (eat.empty()) 
			break;
		else {
			sort(eat.begin(), eat.end());
			eat_count++;
			result += eat[0].first.first;
			map[eat[0].first.second][eat[0].second] = 0;
			b_x = eat[0].first.second; 
			b_y = eat[0].second;
			if (b_size == eat_count) {
				b_size++; 
				eat_count = 0;
			}
		}
	}
	cout << result;
	return 0;
}