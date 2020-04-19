#include<iostream>
#include<algorithm>
using namespace std;

int first(int a) {
	if (a == 1)
		return 500;
	else if (a > 1 && a <= 3)
		return 300;
	else if (a > 3 && a <= 6)
		return 200;
	else if (a > 6 && a <= 10)
		return 50;
	else if (a > 10 && a <= 15)
		return 30;
	else if (a > 15 && a <= 21)
		return 10;
	else
		return 0;
}

int second(int a) {
	if (a == 1)
		return 512;
	else if (a > 1 && a <= 3)
		return 256;
	else if (a > 3 && a <= 7)
		return 128;
	else if (a > 7 && a <= 15)
		return 64;
	else if (a > 15 && a <= 31)
		return 32;
	else
		return 0;
}

int main(void) {
	int t;
	cin >> t;

	int ans = 0;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		
		ans = (first(a) + second(b)) * 10000;
		cout << ans << "\n";
	}
	return 0;
}