#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m, v;
bool visit[1001];

void bfs(vector<int> *graph) {
	queue<int> q;
	q.push(v);
	visit[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (!visit[next]) {
				cout << next << " ";
				q.push(next);
				visit[next] = true;
			}
		}
	}
}

void dfs(vector<int> *graph, int index) {
	cout << index << " ";
	visit[index] = true;

	for (int i = 0; i < graph[index].size(); i++) {
		int next = graph[index][i];
		if (!visit[next])
			dfs(graph, next);
	}
}

int main() {
	cin >> n >> m >> v;
	vector<int> *graph = new vector<int>[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	memset(visit, false, sizeof(visit));
	dfs(graph, v);
	cout << "\n";
	memset(visit, false, sizeof(visit));
	bfs(graph);
	return 0;
}