#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	int c = k;
	int num = 0;
	for (int i = 0; i < 9; i++) {
		long long temp = (pow(10, i) * 9) * (i + 1);
		if (c <= temp) {
			int val = ceil((double)c / double(i + 1));
			num += val;
			string str = to_string(num);
			if (num <= n) {
				int a = c % (i + 1);
				a += i;
				cout << str[a % (i + 1)];
				return 0;
			}
			else {
				cout << -1;
				return 0;
			}
		}
		else {
			c -= temp;
			num += (pow(10, i) * 9);
		}
	}
	return 0;
}