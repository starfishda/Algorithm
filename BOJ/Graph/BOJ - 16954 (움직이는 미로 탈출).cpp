#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

char map[8][8];
int dy[9] = { -1,0,1,1,1,0,-1,-1,0 };
int dx[9] = { 1,1,1,0,-1,-1,-1,0,0 };
bool visit[9][8][8];

int main() {
	string str;

	for (int i = 0; i < 8; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++)
			map[i][j] = str[j];
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0,7,0 });
	visit[0][7][0] = true;

	bool flag = false;

	while (!q.empty()) {
		int t, y, x;
		tie(t, y, x) = q.front();
		q.pop();

		if ((y == 0 && x == 7) || t >= 8) {
			flag = true;
			break;
		}

		for (int i = 0; i < 9; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = t + 1;

			if (!(0 <= ny && ny < 8 && 0 <= nx && nx < 8)) 
				continue;
			if (ny - t >= 0 && map[ny - t][nx] == '#') //벽
				continue;
			if (ny - t - 1 >= 0 && map[ny - t - 1][nx] == '#') //내려온 벽
				continue;

			if (!visit[nt][ny][nx]) {
				visit[nt][ny][nx] = true;
				q.push({ nt,ny,nx, });
			}
		}
	}

	if (flag)
		cout << 1;
	else
		cout << 0;
	return 0;
}