#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int move[101] = { 0, };
	int check[101];
	memset(check, -1, sizeof(check));

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		move[a] = b;
	}

	queue<int> q;
	q.push(1);
	check[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (next > 100)
				continue;

			if (move[next] != 0)
				next = move[next];

			if (check[next] == -1) {
				check[next] = check[now] + 1;
				q.push(next);
			}
		}
	}
	cout << check[100];
	return 0;
}