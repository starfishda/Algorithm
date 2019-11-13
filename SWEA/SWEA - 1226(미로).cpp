#include<stdio.h>
#include<string.h>

using namespace std;

int ori[17][17];
int wall[17][17]; // 왔던 길 체크
int move_x[4] = { 0, -1, 1, 0 };
int move_y[4] = { 1, 0, 0, -1};
int answer = 0;

void cal(int x, int y)
{
	if (ori[x][y] == 3) // 3걸리면 답 1 하고 함수 종료..
	{
		answer = 1;
		return;
	}

	wall[x][y] = 1; // 벽 1로 채워주고...

	//재귀를 넣어줘야하는데....시ㅐㄷ;ㅣㅏ.....
	//사방으로 다 가야하는데 0,1 / -1,0 / 1,0 / 0,-1
	//이동한게 16보다 작아야하고...0이 쓰인 칸이여야하고...3도...
	//ori는 0/3 -> wall -> 0
	for (int i = 0; i < 4; i++)
	{
		int a = x + move_x[i];
		int b = y + move_y[i];
		if (a < 16 && b < 16 && wall[a][b] == 0 && (ori[a][b] == 0 || ori[a][b] == 3))
			cal(a, b);
	}
}

int main()
{
	int test_case;
	for (int i = 1; i <= 10; i++)
	{
		int x, y;
		scanf("%d", &test_case);
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				scanf("%1d", &ori[j][k]);
				if (ori[j][k] == 2)
				{
					x = j;
					y = k;
				}
			}
		}
		cal(x, y);
		printf("#%d %d\n", test_case, answer);
		memset(ori, 0, sizeof(ori)); // 0으로 초기화 개꿀
		memset(wall, 0, sizeof(wall));
		answer = 0;
	}
	return 0;
}