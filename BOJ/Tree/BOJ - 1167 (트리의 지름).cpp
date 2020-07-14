#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[100001];
bool visit[100001];

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
	int v;
	cin >> v;

	for (int i = 0; i < v; i++) {
		int a;
		cin >> a;

		while (true) {
			int b, dis;
			cin >> b;
			if (b == -1)
				break;

			cin >> dis;
			tree[a].push_back({ b, dis });
		}
	}

	memset(visit, false, sizeof(visit));
	dfs(1, 0);

	answer = 0;
	memset(visit, false, sizeof(visit));
	dfs(node_one, 0);

	cout << answer;
	return 0;
}