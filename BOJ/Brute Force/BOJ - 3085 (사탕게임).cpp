#include<iostream>
#include<algorithm>
using namespace std;

int n, ans = 0;
char arr[50][50];

void candy() {
	int num = 0;
	for (int r = 0; r < n; r++) {
		num = 1;
		for (int k = 1; k < n; k++) {
			if (arr[k - 1][r] == arr[k][r])
				num++;
			else {
				ans = max(ans, num);
				num = 1;
			}
		}
		ans = max(ans, num);
	}

	for (int r = 0; r < n; r++) {
		int num = 1;
		for (int k = 1; k < n; k++) {
			if (arr[r][k - 1] == arr[r][k])
				num++;
			else {
				ans = max(ans, num);
				num = 1;
			}
		}
		ans = max(ans, num);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { // 배열 입력
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(arr[i][j], arr[i][j + 1]);
				candy(); //확인
				swap(arr[i][j], arr[i][j + 1]); //원상복구
			}
			if (i + 1 < n) {
				swap(arr[i][j], arr[i + 1][j]);
				candy();
				swap(arr[i][j], arr[i + 1][j]);
			}
		}
	}

	cout << ans << "\n";
	return 0;
}