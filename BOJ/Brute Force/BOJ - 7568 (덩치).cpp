#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);//입출력 속도 향상
	cin.tie(0);

	int n;
	cin >> n;

	int *x = new int[n];
	int *y = new int[n];

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = 0; j < n; j++) {

			if (i == j)
				continue;

			if (x[i] < x[j] && y[i] < y[j])
				num++;
		}
		cout << num + 1 << " ";
	}
	return 0;
}