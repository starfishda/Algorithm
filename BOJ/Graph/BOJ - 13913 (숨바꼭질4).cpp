#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include<cstring>
#include<algorithm>

using namespace std;
int n, k;
int check[100001];
int dis[100001];

void bfs() {
	queue<int> q;
	check[n] = 1;
	q.push(n);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (node == k)
			return;

		if (node * 2 <= 100000 && check[node * 2] == 0) {
			check[node * 2] = check[node] + 1;
			q.push(node * 2);
			dis[node * 2] = node;
		}

		if (node - 1 >= 0 && check[node - 1] == 0) {
			check[node - 1] = check[node] + 1;
			q.push(node - 1);
			dis[node - 1] = node;
		}

		if (node + 1 <= 100000 && check[node + 1] == 0) {
			check[node + 1] = check[node] + 1;
			q.push(node + 1);
			dis[node + 1] = node;
		}
	}
}

int main() {
	cin >> n >> k;

	memset(check, 0, sizeof(check));
	memset(dis, -1, sizeof(dis));

	bfs();

	vector<int> answer;
	int index = k;
	while (k != n) {
		answer.push_back(dis[k]);
		k = dis[k];
	}
	
	cout << check[index] - 1 << "\n";

	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i] << " ";
	cout << index;
	return 0;
}