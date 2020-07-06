#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int num;

	for (int i = 1; i < n * 2; i++) {
		if (i > n)
			num = n * 2 - i;
		else
			num = i;

		for (int j = 0; j < n - num; j++)
			cout << " ";
		for (int j = 0; j < num; j++)
			cout << "*";
		cout << "\n";
	}
	return 0;
}