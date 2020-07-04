#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> answer;
	string str = "";
	string copy = "";

	for (int i = 1; i <= n; i++) {
		str = "";
		for (int j = 1; j <= i; j++) {
			str += "*";
			cout << "*";
		}
		for (int j = 1; j <= n - i; j++) {
			str += " ";
			cout << " ";
		}
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}

	for (int i = n - 1; i >= 1; i--) {
		str = "";
		for (int j = 1; j <= i; j++) {
			str += "*";
			cout << "*";
		}
		for (int j = 1; j <= n - i; j++) {
			str += " ";
			cout << " ";
		}
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}

	return 0;
}