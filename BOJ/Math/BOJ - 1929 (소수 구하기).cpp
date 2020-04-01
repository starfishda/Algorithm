#include<iostream>
#include<algorithm>
using namespace std;
bool arr[1000001];

int main() {
	int m, n;
	cin >> m >> n;

	for (int i = 0; i <= n; i++) {
		arr[i] = true;
	}

	arr[1] = false;

	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				arr[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i])
			cout << i << "\n";
	}
	return 0;
}