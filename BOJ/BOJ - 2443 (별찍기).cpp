#include<stdio.h>

void main()
{
	int num;
	scanf("%d", &num);

	for (int i = num; i > 0; i--)
	{
		for (int k = 0; k < num - i; k++)
		{
			printf(" ");
		}

		for (int j = 0; j < i *2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}