#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 10;

int row, col; //가로, 세로
int minCnt = INF;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

typedef struct
{
	int y, x;
}Coord;

void tilt(string board[MAX], int dir, int cnt, Coord R, Coord B) {
	if (++cnt > 10)
		return;

	string copy[MAX];
	for (int i = 0; i < col; i++)
		copy[i] = board[i]; 

	bool red = false, blue = false;

	int order = 0;

	switch (dir) {
	case 0:
		if (B.y < R.y) //B가 R보다 위에 있을 경우
			order = 1;
		break;
	case 1:
		if (B.x < R.x) //B가 R보다 왼쪽에 있을 경우
			order = 1;
		break;
	case 2:
		if (R.x < B.x) //B가 R보다 오른쪽에 있을 경우
			order = 1;
		break;
	case 3:
		if (R.y < B.y) //R이 B보다 위에 있을 경우
			order = 1;
		break;
	}

	if (order == 0) {
		while (1) { // 빨간 구슬
			int nextY = R.y + dy[dir];
			int nextX = R.x + dx[dir];

			if (copy[nextY][nextX] == '#') //막히면 그만 움직인다
				break;

			if (copy[nextY][nextX] == 'O') 	{
				copy[R.y][R.x] = '.';
				R.y = R.x = -1;
				red = true;
				break;
			}

			copy[R.y][R.x] = '.';
			copy[nextY][nextX] = 'R';
			R.y = nextY;
			R.x = nextX;
		}

		while (1) { 
			int nextY = B.y + dy[dir];
			int nextX = B.x + dx[dir];

			if (copy[nextY][nextX] == '#' || copy[nextY][nextX] == 'R') 
				break;

			if (copy[nextY][nextX] == 'O') {
				copy[B.y][B.x] = '.';
				B.y = B.x = -1;
				blue = true;
				break;
			}
			copy[B.y][B.x] = '.';
			copy[nextY][nextX] = 'B';
			B.y = nextY;
			B.x = nextX;
		}
	}

	else {
		while (1) { //파란 구슬
			int nextY = B.y + dy[dir];
			int nextX = B.x + dx[dir];

			if (copy[nextY][nextX] == '#')
				break;

			if (copy[nextY][nextX] == 'O') {
				copy[B.y][B.x] = '.';
				B.y = B.x = -1;
				blue = true;
				break;
			}
			copy[B.y][B.x] = '.';
			copy[nextY][nextX] = 'B';
			B.y = nextY;
			B.x = nextX;
		}

		while (1){
			int nextY = R.y + dy[dir];
			int nextX = R.x + dx[dir];

			if (copy[nextY][nextX] == '#' || copy[nextY][nextX] == 'B')
				break;

			if (copy[nextY][nextX] == 'O') {
				copy[R.y][R.x] = '.';
				R.y = R.x = -1;
				red = true;
				break;
			}
			copy[R.y][R.x] = '.';
			copy[nextY][nextX] = 'R';
			R.y = nextY;
			R.x = nextX;
		}
	}

	if (blue) //파란 구슬 홀 x
		return;
	else if (red){

		minCnt = min(cnt, minCnt);
		return;
	}

	for (int i = 0; i < 4; i++)
		if (i != dir || i != (3 - dir))
			tilt(copy, i, cnt, R, B);
}

int main(void) {
	Coord R, B;
	string board[MAX];
	cin >> col >> row;

	if (col < 3 || col>10 || row < 3 || row>10)
		exit(-1);

	for (int i = 0; i < col; i++) {
		cin >> board[i];
		for (int j = 0; j < row; j++)
			if (board[i][j] == 'R')
				R.y = i, R.x = j;
			else if (board[i][j] == 'B')
				B.y = i, B.x = j;
	}

	for (int i = 0; i < 4; i++) 
		tilt(board, i, 0, R, B);

	if (minCnt == INF)
		cout << -1;
	else
		cout << minCnt;
	return 0;
}