#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct
{
	int y, x;
}dir;
dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int n, m;
int graph[1000][1000];
int cache[1000][1000][2];

int bfs(void) {
	queue < pair<pair<int, int>, int>> q; 
	q.push(make_pair(make_pair(0, 0), 1)); 
	cache[0][0][1] = 1;

	while (!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (y == n - 1 && x == m - 1)
			return cache[y][x][block]; 

		for (int i = 0; i < 4; i++)	{
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)	{
				if (graph[nextY][nextX] == 1 && block) { // º® + ¶Õ±â Àü
					cache[nextY][nextX][block - 1] = cache[y][x][block] + 1;
					q.push(make_pair(make_pair(nextY, nextX), block - 1));
				}
				else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0) {
					cache[nextY][nextX][block] = cache[y][x][block] + 1;
					q.push(make_pair(make_pair(nextY, nextX), block));
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < m; j++)
			graph[i][j] = temp[j] - '0';
	}

	cout << bfs() << endl;
	return 0;
}