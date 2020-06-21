#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m; //µµÂø ÁÂÇ¥
int map[101][101]; // ¹Ì·Î ¸Ê
int check[101][101] = { 0, };
int distance = 1;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	check[0][0] = 1;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		if (cur_x == m - 1 && cur_y == n - 1)
			break;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && check[next_y][next_x] == 0 && map[next_y][next_x] == 1) {
				check[next_y][next_x] = check[cur_y][cur_x] + 1;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}

int main() {
	cin >> n >> m;

	// Áöµµ ¸Ê ÀÔ·Â
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
			check[i][j] = 0;
		}
	}

	bfs();
	cout << check[n - 1][m - 1]<<"\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << check[i][j] << "  ";
		}
		cout << "\n";
	}
	return 0;
}