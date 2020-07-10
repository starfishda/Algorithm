#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> tree[100001];
bool visit[100001];
int answer[100001];

void dfs(int num) {
	visit[num] = true;

	for (int i = 0; i < tree[num].size(); i++) {
		int next = tree[num][i];

		if (!visit[next]) {
			answer[next] = num;
			dfs(next);
		}
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}