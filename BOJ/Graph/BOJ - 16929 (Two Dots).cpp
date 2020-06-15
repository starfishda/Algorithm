#include <iostream>
#include <vector>
#include<cstring>

using namespace std;
int n, m;
char color[51][51];
int dis[51][51] = { 0, };
bool check[51][51] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
char cur_color;

bool dfs(int x, int y, int cnt) {
	if (check[x][y]) {
		if (cnt - dis[x][y] >= 3)
			return true;
		else
			return false;
	}

	check[x][y] = true;
	dis[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && color[next_x][next_y] == cur_color)
			if (dfs(next_x, next_y, cnt + 1))
				return true;
	}
	return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(dis, 0, sizeof(dis));
			if (!check[i][j]) {
				cur_color = color[i][j];
				if (dfs(i, j, 1)) {
					cout << "Yes";
					return 0;
				}
			}
		}
		
	}
	cout << "No";
	return 0;
}