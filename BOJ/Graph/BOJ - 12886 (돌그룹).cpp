#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
int a, b, c;
int total;
int ans;
bool visit[1000][1000];

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = total - x - y;
		q.pop();

		if (x == y && x == z) {
			ans = 1;
			return;
		}

		int nx[3] = { x, x, y };
		int ny[3] = { y, z, z };
		for (int i = 0; i < 3; i++) {
			int next_x = nx[i];
			int next_y = ny[i];

			if (next_x < next_y) {
				next_y -= next_x;
				next_x += next_x;
			}
			else if (next_x > next_y) {
				next_x -= next_y;
				next_y += next_y;
			}
			else
				continue;

			int n = min(min(next_x, next_y), total - next_x - next_y);
			int m = max(max(next_x, next_y), total - next_x - next_y);
			if (!visit[n][m]) {
				q.push(make_pair(n, m));
				visit[n][m] = true;
			}
		}
	}
	ans = 0;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> a >> b >> c;
	total = a + b + c;

	if (total % 3 != 0)
		ans = 0;
	else
		bfs();

	cout << ans;
	return 0;
}