#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visit[10001];

int answer = 0;
int node_one = 0;

void dfs(int node, int dis) {
	if (visit[node])
		return;

	visit[node] = true;

	if (answer < dis) {
		answer = dis;
		node_one = node;
	}

	for (int i = 0; i < tree[node].size(); i++)
		dfs(tree[node][i].first, dis + tree[node][i].second);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b, dis;
		cin >> a >> b >> dis;

		tree[a].push_back(make_pair(b, dis));
		tree[b].push_back(make_pair(a, dis));
	}

	memset(visit, false, sizeof(visit));
	dfs(1, 0);

	answer = 0;
	memset(visit, false, sizeof(visit));
	dfs(node_one, 0);

	cout << answer;
	return 0;
}