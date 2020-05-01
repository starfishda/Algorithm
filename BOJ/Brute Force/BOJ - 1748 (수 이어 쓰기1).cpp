#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int c_n = n;
	int count = 1;

	while (n >= 10) {
		count++;
		n /= 10;
	}

	int ans = 0;
	
	if (count == 1)
		ans = n;
	else {
		for (int i = 1; i <= count; i++) {
			if (i == count)
				ans += ((c_n - pow(10, i - 1) + 1) * i);
			else
				ans += ((pow(10, i) - pow(10, i - 1)) * i);
		}
	}

	cout << ans << "\n";
	return 0;
}