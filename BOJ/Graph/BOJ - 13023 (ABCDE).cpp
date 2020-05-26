#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n, m;
bool visit[2001];
bool ans = false;
vector<int> v[2001];

void dfs(int idx, int cnt) {
	if (cnt == 4) {
		ans = true;
		return;
	}

	visit[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		int n_idx = v[idx][i];
		if (!visit[n_idx]) {
			dfs(n_idx, cnt + 1);
		}
		if (ans) 
			return;
	}
	visit[idx] = false;
}

int main() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, 0);
		if (ans) 
			break;
	}

	if (ans)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}