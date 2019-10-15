/*
#################################C++은 FAIL  C는 PASS######################################

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	long long N;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		long long check = 0;
		int flag = 0; // 0 = 앨리스, 1 = 밥

		if (N == 2 || N == 3)
			cout << "#" << test_case << " Alice" << endl;
		else if (N == 1)
			cout << "#" << test_case << " Bob" << endl;

		while (N > ((long long)1 << check)) // 층을 구한다 // 2진수 단위로...
			check++;

		if (check % 2 == 1) // 누구 층일지
			flag = 1; // N은 밥 층에 위치
		else
			flag = 0; // N은 앨리스 층에 위치

		long long x = 1;
		int copy_flag = 1;
		int depth = 0;

		if (flag == 1) // 만약 밥 층이면
		{
			copy_flag = 1; // 밥이면 2x+1을 해줘야하고, 앨리스면 2x를 해줘야한다

			while ((depth + 1) != check)
			{
				if (copy_flag == 1)
					x = 2 * x + 1;
				else
					x = 2 * x;
				copy_flag = copy_flag ^ 1;
				depth++;
			}
		}
		else // 앨리스 층이면
		{
			copy_flag = 0;

			while ((depth + 1) != check)
			{
				if (copy_flag == 1)
					x = 2 * x + 1;
				else
					x = 2 * x;
				copy_flag = copy_flag ^ 1;
				depth++;
			}
		}

		if (flag == 1) // 밥 층일 때는
		{
			if (N >= x)
				cout << "#" << test_case << " Bob" << endl;
			else
				cout << "#" << test_case << " Alice" << endl;
		}
		else
		{
			if (N >= x)
				cout << "#" << test_case << " Alice" << endl;
			else
				cout << "#" << test_case << " Bob" << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}*/


/*
######################### C로 짜면 PASS  // C++은 FAIL ##############################

#include<stdio.h> 

#define Alice true
#define Bob false

int main(void)
{
	int T;
	long long N;
	bool turn;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &N);
		turn = Alice;
		long long x = 1;

		while (N > 0)
		{
			N -= x;
			if (turn)
				x *= 4;
			turn = !turn;
		}
		if (turn)
			printf("#%d Alice\n", test_case);
		else
			printf("#%d Bob\n", test_case);
	}
	return 0;
}*/

//######################### C로 짜면 PASS  // C++은 FAIL ##############################
#include<stdio.h> 

int main(void)
{
	int T;
	long long N;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &N);

		while (N > 10)
		{
			N = N / 2 + 1;
			N = N / 2 - 1;
		}

		if (N == 1 || (N >= 6 && N <= 9))
			printf("#%d Bob\n", test_case);
		else
			printf("#%d Alice\n", test_case);
	}
	return 0;
}


/*#include<iostream>
using namespace std;

#define Alice true
#define Bob false

int main()
{
	int T;
	long long N;
	bool turn;
	scanf("%d", &T);

	while (T--)
	{
		cin >> N;
		turn = Alice;
		long long x = 1;

		while (N > 0)
		{
			N -= x;
			if (turn)
				x *= 4;
			turn = !turn;
		}

		if(turn)
			cout << "#" << T << " Alice" << endl;
		else
			cout << "#" << T << " Bob" << endl;
=================================================================
		long N;   //4만 몇개 정답
		cin >> N;

		while (N > 10)
		{
			N = N / 2 + 1;
			N = N / 2 - 1;
		}

		if (N == 1 || (N >= 6 && N <= 9))
			cout << "#" << T << " Bob" << endl;
		else
			cout << "#" << T << " Alice" << endl;
	}
}*/