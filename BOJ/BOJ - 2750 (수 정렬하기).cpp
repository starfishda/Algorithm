#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
	return 0;
}