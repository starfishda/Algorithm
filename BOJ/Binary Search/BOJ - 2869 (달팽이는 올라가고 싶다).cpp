#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, v;
	cin >> a >> b >> v;

	if ((v - b) % (a - b) != 0)
		cout << (v - b) / (a - b) + 1;
	else
		cout << (v - b) / (a - b);

	return 0;
}