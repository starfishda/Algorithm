#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j <= i; j++)
			ans += arr[j];
	}
	cout << ans;
	return 0;
}