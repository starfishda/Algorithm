#include<stdio.h>

void main()
{
	//input 5
	int num;
	scanf("%d", &num);
	//1 3 5 7 9

	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			printf(" ");
		}

		int count = i * 2 - 1;
		for (int k = 0; k < count; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}