#include<iostream>
#include<algorithm>
using namespace std;
bool arr[1000001];

int main() {
	int t;
	cin >> t;

	for (int j = 0; j < t; j++) {
		int n;
		cin >> n;

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
		int count = 0;
		int i = n / 2;
		while (i >= 1 && count == 0) {
			if (arr[i] == true && arr[n - i] == true) {
				cout << i << " " << n - i << "\n";
				count++;
			}
			i--;
		}
	}
	
	return 0;
}