#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[21][21];
bool visit[26];
int r, c;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dfs(int front, int back) {
	int ans(0);
	visit[map[front][back]] = true;

	for (int i = 0; i < 4; i++) {
		int next_front = front + dy[i];
		int next_back = back + dx[i];

		if (next_front >= 0 && next_front < r && next_back >= 0 && next_back < c && !visit[map[next_front][next_back]]) {
			ans = max(ans, dfs(next_front, next_back));
		}
	}

	visit[map[front][back]] = false;
	return ans + 1;
}

int main() {
	cin >> r >> c;
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char a;
			cin >> a;
			map[i][j] = a - 'A';
		}
	}


	cout << dfs(0, 0);
	return 0;
}