#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int max_num = -1000000;
	int min_num = 1000000;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		max_num = max(max_num, a);
		min_num = min(min_num, a);
	}
	cout << min_num << " " << max_num;

	return 0;
}