#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[10];
	int ans[42] = { 0, };
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		ans[arr[i] % 41] += 1;
	}

	for (int i = 0; i < 42; i++) {
		if (ans[i] != 0)
			sum += 1;
	}

	cout << sum << endl;
	return 0;
}