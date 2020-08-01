#include<iostream>
#include<queue>
#include<string>
#include<cstring>

using namespace std;
int map[9][9];
bool row[9][10] = { false, };
bool col[9][10] = { false, };
bool box[9][10] = { false, };
int cnt = 0;

int value(int a, int b) {
	return 3 * (a / 3) + (b / 3);
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cnt++;
}

void sdoku() {
	int a = -1, b = -1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				a = i;
				b = j;
				break;
			}
		}
		if (a != -1)
			break;
	}

	if (a == -1) {
		print();
	}

	if (cnt == 1)
		return;

	for (int i = 1; i < 10; i++) {
		if (!row[a][i] && !col[b][i] && !box[value(a, b)][i]) {
			row[a][i] = true;
			col[b][i] = true;
			box[value(a, b)][i] = true;
			map[a][b] = i;
			sdoku();
			map[a][b] = 0;
			row[a][i] = false;
			col[b][i] = false;
			box[value(a, b)][i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];

			row[i][map[i][j]] = true;
			col[j][map[i][j]] = true;
			box[value(i, j)][map[i][j]] = true;
		}
	}

	sdoku();
	return 0;
}