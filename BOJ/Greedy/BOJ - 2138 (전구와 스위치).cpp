#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int a_c[100001];
int b[100001];
int cnt = 0;

bool compare(int c[], int n)
{
	for (int i = 1; i <= n; ++i) {
		if (c[i] != b[i])
			return false;
	}
	return true;
}

void change(int c[], int ch, int n)
{
	for (int i = -1; i <= 1; i++) {
		if (ch + i > 0 && ch + i <= n)
			c[ch + i] = 1 - c[ch + i];
	}
	cnt++;
}

int main(void)
{
	int n;
	cin >> n;


	for (int i = 1; i <= n; ++i) {
		scanf("%1d", &a[i]);
		a_c[i] = a[i];
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%1d", &b[i]);
	}

	change(a, 1, n);

	int one = 1;
	int two = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i - 1] != b[i - 1]) {
			change(a, i, n);
			one++;
		}
		if (a_c[i - 1] != b[i - 1]) {
			change(a_c, i, n);
			two++;
		}
	}

	int ans = -1;
	if (compare(a, n))
		ans = one;
	else if (compare(a_c, n))
		ans = two;

	if (compare(a, n) && compare(a_c, n))
		ans = min(one, two);

	cout << ans << endl;

	return 0;
}
