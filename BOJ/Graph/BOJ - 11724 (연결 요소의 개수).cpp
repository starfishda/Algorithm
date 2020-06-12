#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
bool check[1001];
vector<int> graph[1001];

void dfs(int a) {
	check[a] = true;
	for (int i = 0; i < graph[a].size(); i++) {
		int next = graph[a][i];
		if(!check[next])
			dfs(next);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
	return 0;
}