#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int map[26][26];
bool visit[26][26];
vector<int> answer;
int n;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int i, int  j, int cnt) {
	queue <pair<int, int>> q;
	visit[i][j] = true;
	q.push(make_pair(i, j));
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int t = 0; t < 4; t++) {
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && map[nx][ny] == 1) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
				cnt++;
			}
		}
	}
	answer.push_back(cnt);
}

int main() {
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1)
				bfs(i, j, 1);
		}
	}
	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";
	return 0;
}