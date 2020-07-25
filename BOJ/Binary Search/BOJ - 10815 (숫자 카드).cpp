#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;
	int *find = new int[m];
	for (int i = 0; i < m; i++)
		cin >> find[i];

	sort(arr, arr + n);

	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n - 1;
		int flag = false;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] == find[i]) {
				flag = true;
				break;
			}
			else if (arr[mid] < find[i])
				left = mid + 1;
			else
				right = mid - 1;
		}

		if (!flag)
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}

	return 0;
}