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

void bfs() {
	queue<int> q;
	check[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (node == k)
			return;

		if (node - 1 >= 0 && check[node - 1] == 0) {
			check[node - 1] = check[node] + 1;
			q.push(node - 1);
		}

		if (node + 1 <= 100000 && check[node + 1] == 0) {
			check[node + 1] = check[node] + 1;
			q.push(node + 1);
		}

		if (node * 2 <= 100000 && check[node * 2] == 0) {
			check[node * 2] = check[node] + 1;
			q.push(node * 2);
		}
	}
}

int main() {
	cin >> n >> k;

	memset(check, 0, sizeof(check));
	bfs();
	
	cout << check[k];
	return 0;
}