#include<iostream>
using namespace std;

int main() {
	int e, s, m;
	int ans = 0;
	cin >> e >> s >> m;
	int c_e = 0, c_s = 0, c_m = 0;

	while (e != c_e || s != c_s || m != c_m) {
		ans++;
		c_e = ans % 15;
		c_s = ans % 28;
		c_m = ans % 19;

		if (c_e == 0)
			c_e = 15;
		if (c_s == 0)
			c_s = 28;
		if (c_m == 0)
			c_m = 19;
	}
	cout << ans << endl;
	return 0;
}