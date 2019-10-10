#include<stdio.h>
#include<stdlib.h>

int Answer;

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}

int main(void) {
	int T, test_case;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int max = 0;

		int N;
		scanf("%d", &N); //응시자의 수 입력받기
		
		int *score;
		score = (int *)malloc(sizeof(int)*N);

		for (int i = 0; i < N; i++)
			scanf("%d", &score[i]); //응시자 각각의 점수  입력받기
		
		qsort(score, N, sizeof(int), compare); //정렬 5,4,3

		for (int i = 0; i < N; i++)
			if ((score[i] + N - i) >= max)
				max = (score[i] + N - i);

		for (int i = 0; i < N; i++)
			if (max <= (score[i] + N))
				Answer++;

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	scanf("%d", &Answer);
	return 0;
}