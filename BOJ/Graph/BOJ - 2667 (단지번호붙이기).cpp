#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n; 
int map[26][26]; // ¹Ì·Î ¸Ê
bool visit[26][26] = { false, };
int check[26][26] = { 0, };

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs(int x, int y, int count) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;
	check[y][x] = count;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visit[next_y][next_x] && map[next_y][next_x] == 1) {
				check[next_y][next_x] = count;
				visit[next_y][next_x] = true;
				q.push(make_pair(next_x, next_y));
			}
		}
	}
}

int main() {
	cin >> n;

	// Áöµµ ¸Ê ÀÔ·Â
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
			check[i][j] = 0;
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && !visit[i][j]) {
				count++;
				bfs(j, i, count);
			}
		}
	}
	int *arr = new int[count + 1];

	for (int i = 0; i <= count; i++)
		arr[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] != 0)
				arr[check[i][j]]++;
		}
	}
	sort(arr, arr + count + 1);
	cout << count << "\n";

	for (int i = 1; i <= count; i++)
		cout << arr[i] << "\n";
	return 0;
}