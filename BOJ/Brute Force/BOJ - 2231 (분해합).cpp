#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 1;

	while (1) {
		int copy = ans;
		int sum = ans;

		while (copy) {
			sum += copy % 10;
			copy /= 10;
		}

		if (ans == n || sum == n)
			break;

		ans++;
	}

	if (ans == n)
		cout << 0 << "\n";
	else
		cout << ans << "\n";

	return 0;
}