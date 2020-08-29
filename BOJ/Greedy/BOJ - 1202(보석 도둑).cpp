#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	int n, k; // 보석 수, 가방 수
	cin >> n >> k; 

	vector<pair<int, int>> stone;
	int m, v;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		stone.push_back(make_pair(m, v));
	}
	sort(stone.begin(), stone.end());

	int c;
	vector<int> bag;
	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}
	sort(bag.begin(), bag.end());

	long long ans = 0;
	priority_queue<int> q;
	for (int i = 0, j = 0; i < k; i++) {
		while (j < n && stone[j].first <= bag[i])
			q.push(stone[j++].second);

		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}

	cout << ans;
	return 0;
}