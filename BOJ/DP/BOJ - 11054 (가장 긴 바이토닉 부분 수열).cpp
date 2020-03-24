#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n;
	int in[1000] = {};
	int de[1000] = {};
	int arr[1000] = {};
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		in[i] = 1;
		de[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				in[i] = max(in[i], in[j] + 1);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
				de[i] = max(de[i], de[j] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		sum = max(sum, in[i] + de[i] - 1);
	}

	cout << sum << endl;
	return 0;
}