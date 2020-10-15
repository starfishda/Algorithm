#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[21][21];
int answer = 987654321;

void count_answer(int x, int y, int d1, int d2) {
	int arr[5] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < x + d1 && j <= y && !(i >= x && j >= y - (i - x)))
				arr[0] += map[i][j];
			else if (i <= x + d2 && j > y && !(i >= x && j <= y + (i - x)))
				arr[1] += map[i][j];
			else if (i >= x + d1 && j < y - d1 + d2 && !(i <= x + d1 + d2 && j >= (y - d1 + d2 - (x + d1 + d2 - i))))
				arr[2] += map[i][j];
			else if (i > x + d2 && j >= y - d1 + d2 && !(i <= x + d1 + d2 && j <= (y - d1 + d2 + (x + d1 + d2 - i))))
				arr[3] += map[i][j];
			else
				arr[4] += map[i][j];
		}
	}

	sort(arr, arr + 5);
	answer = min(answer, arr[4] - arr[0]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> map[i][j];
		
	for (int r = 1; r <= n - 2; r++) {
		for (int c = 2; c <= n - 1; c++) {
			for (int d1 = 1; d1 <= c - 1 && d1 <= n - r - 1; d1++) {
				for (int d2 = 1; d2 <= n - c && d2 <= n - r - 1; d2++) {
					count_answer(r, c, d1, d2);
				}
			}
		}
	}

	cout << answer;
}