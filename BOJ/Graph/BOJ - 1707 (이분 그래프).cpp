#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include<cstring>
#include<algorithm>

using namespace std;
int v, e;
bool visit[20001];
int color[20001];
int answer = true;

void bfs(int start, vector<int> graph[]) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	color[start] = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (!visit[next]) {
				color[next] = 3 - color[current];
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

void dfs(vector<int> graph[], int index) {
	visit[index] = true;
	for (int i = 0; i < graph[index].size(); i++) {
		int next = graph[index][i];
		if (color[index] == color[next]) {
			answer = false;
			return;
		}
		if(!visit[next])
			dfs(graph, next);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		vector<int> graph[20001];
		answer = true;
		memset(visit, false, sizeof(visit));
		memset(color, 0, sizeof(color));
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int k = 1; k <= v; k++) {
			if(!visit[k])
				bfs(k, graph);

		}
		for (int k = 1; k <= v; k++) {
			if (!answer)
				break;
			dfs(graph, k);

		}

		if (answer)
		   cout << "YES\n";
		else
		   cout << "NO\n";
	}
	return 0;
}