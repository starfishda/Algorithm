#include<iostream>

using namespace std;
int map[3000][3000];
int ans[3] = { 0, };
int n;

void recur(int x, int y, int a) {
	int temp = map[x][y];

	for (int i = x; i < x + a; i++) {
		for (int j = y; j < y + a; j++) {
			if (temp == -1 && map[i][j] != -1)
				temp = 2;
			if (temp == 1 && map[i][j] != 1)
				temp = 2;
			if (temp == 0 && map[i][j] != 0)
				temp = 2;

			if (temp == 2) {
				int num = a / 3;
				recur(x, y, num);
				recur(x + num, y, num);
				recur(x + num * 2, y, num);

				recur(x, y + num, num);
				recur(x + num, y + num, num);
				recur(x + num * 2, y + num, num);

				recur(x, y + num * 2, num);
				recur(x + num, y + num * 2, num);
				recur(x + num * 2, y + num * 2, num);
				return;
			}
		}
	}

	if (temp == -1)
		ans[0]++;
	else if (temp == 0)
		ans[1]++;
	else if (temp == 1)
		ans[2]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	recur(0, 0, n);

	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
	return 0;
}