#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, i;
		unsigned int num;
		scanf("%d", &N);
		scanf("%d", &Answer);
		for (i = 0; i<N - 1; i++)
		{
			scanf("%d", &num);
			Answer ^= num;
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
