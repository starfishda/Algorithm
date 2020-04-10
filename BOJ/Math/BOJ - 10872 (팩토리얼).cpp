#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 1;
	while (n >= 1) {
		sum *= n;
		n--;
	}

	cout << sum << endl;
	return 0;
}