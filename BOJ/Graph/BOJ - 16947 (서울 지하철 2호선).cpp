#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
vector<int> graph[3001];
bool cycle;
bool visit[3001] = { false, };
bool circle[3001] = { false, }; // ��ȯ���ΰ� true��
int answer[3001]; // �� �־��ְ�
int check[3001]; // bfs ������������ �Ÿ� Ž��

// ��ȯ�� ã��
void dfs(int start, int current, int count) {
	if (start == current && count >= 3) {
		cycle = true;
		return;
	}

	visit[current] = true;
	for (int i = 0; i < graph[current].size(); i++) {
		if (!visit[graph[current][i]])
			dfs(start, graph[current][i], count + 1);
		else {
			if(start == graph[current][i] && count >= 3)
				dfs(start, graph[current][i], count);
		}

		if (cycle)
			return;
	}
	return;
}

// �ּҰŸ� Ž��
void bfs(int start) {
	queue<int> q;
	check[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			if (check[graph[node][i]] == -1) { //�湮���� �ʾҴٴ� �ǹ�
				check[graph[node][i]] = check[node] + 1;
				q.push(graph[node][i]);
			}
		}
	}
}

int main() {
	cin >> n;

	// �׷��� ����
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// ���� ��ȯ������ üũ - dfs
	for (int i = 1; i <= n; i++) {
		cycle = false;
		memset(visit, false, sizeof(visit));
		if (!visit[i]) {
			dfs(i, i, 1);
			if (cycle) 
				circle[i] = true;
		}	
	}

	for (int i = 1; i <= n; i++) {
		if (circle[i]) {
			answer[i] = 0;
		}
		else {
			memset(check, -1, sizeof(check));
			bfs(i);
			for (int j = 1; j <= n; j++) {
				if (circle[j] && answer[i] == 0)
					answer[i] = check[j];
				else if (circle[j])
					answer[i] = min(answer[i], check[j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << answer[i] << " ";
	return 0;
}