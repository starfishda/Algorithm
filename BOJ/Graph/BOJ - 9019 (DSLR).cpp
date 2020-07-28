#include<iostream>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

bool visit[10000];
int a, b;

string bfs() {
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));
	visit[a] = true;

	while (!q.empty()) {
		int front = q.front().first;
		string one = q.front().second;
		q.pop();
		if (front == b)
			return one;

		int num = front * 2 % 10000;
		if (!visit[num]) {
			string two = one + "D";
			q.push(make_pair(num, two));
			visit[num] = true;
		}

		if (front == 0)
			num = 9999;
		else
			num = front - 1;
		if (!visit[num]) {
			string two = one + "S";
			q.push(make_pair(num, two));
			visit[num] = true;
		}

		num = (front % 1000) * 10 + front / 1000;
		if (!visit[num]) {
			string two = one + "L";
			q.push(make_pair(num, two));
			visit[num] = true;
		}

		num = (front % 10) * 1000 + front / 10;
		if (!visit[num]) {
			string two = one + "R";
			q.push(make_pair(num, two));
			visit[num] = true;
		}
	}
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		memset(visit, false, sizeof(visit));
		cout << bfs() << "\n";
	}
	return 0;
}