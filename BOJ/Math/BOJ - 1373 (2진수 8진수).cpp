#include<iostream>
#include<string>
using namespace std;

int main() {
	string num;
	cin >> num;
	int n = num.size();

	if (n % 3 == 1)
		cout << num[0];
	else if (n % 3 == 2)
		cout << (num[0] - '0') * 2 + (num[1] - '0');

	for (int i = n % 3; i < n; i += 3) {
		cout << (num[i] - '0') * 4 + (num[i + 1] - '0') * 2 + (num[i + 2] - '0');
	}

	cout << '\n';
	return 0;
}