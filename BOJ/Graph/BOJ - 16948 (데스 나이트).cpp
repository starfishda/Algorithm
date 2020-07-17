#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int map[222][222];
bool checked[222][222];
int dist[222][222];

int dr[] = { -2,-2,0,0,+2,+2 };
int dc[] = { -1,+1,-2,+2,-1,+1 };

int main() {
	cin >> N;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	queue<pair<int, int> > q;
	checked[r1][c1] = true;
	dist[r1][c1] = 0;
	q.push(make_pair(r1, c1));

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (r == r2 && c == c2) {
			break;
		}

		for (int dir = 0; dir < 6; ++dir) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (0 <= nr && nr < N && 0 <= nc && nc < N) {
				if (checked[nr][nc] == false) {
					checked[nr][nc] = true;
					dist[nr][nc] = dist[r][c] + 1;
					q.push(make_pair(nr, nc));
				}
			}
		}
	}
	if (dist[r2][c2] > 0) {
		cout << dist[r2][c2];
	}
	else {
		cout << -1;
	}
	return 0;
}