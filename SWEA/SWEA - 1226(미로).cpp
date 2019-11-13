#include<stdio.h>
#include<string.h>

using namespace std;

int ori[17][17];
int wall[17][17]; // �Դ� �� üũ
int move_x[4] = { 0, -1, 1, 0 };
int move_y[4] = { 1, 0, 0, -1};
int answer = 0;

void cal(int x, int y)
{
	if (ori[x][y] == 3) // 3�ɸ��� �� 1 �ϰ� �Լ� ����..
	{
		answer = 1;
		return;
	}

	wall[x][y] = 1; // �� 1�� ä���ְ�...

	//��͸� �־�����ϴµ�....�ä���;�Ӥ�.....
	//������� �� �����ϴµ� 0,1 / -1,0 / 1,0 / 0,-1
	//�̵��Ѱ� 16���� �۾ƾ��ϰ�...0�� ���� ĭ�̿����ϰ�...3��...
	//ori�� 0/3 -> wall -> 0
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
		memset(ori, 0, sizeof(ori)); // 0���� �ʱ�ȭ ����
		memset(wall, 0, sizeof(wall));
		answer = 0;
	}
	return 0;
}