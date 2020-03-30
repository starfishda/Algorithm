#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0)
			sum++;
		if (i % 25 == 0)
			sum++;
		if (i % 125 == 0)
			sum++;
	}
	cout << sum << endl;
	return 0;
}