#include<iostream>
using namespace std;

int arr[1000001];

int main()
{
	int T, N;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		long answer = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			std::cin >> arr[j];
		}

		int x = arr[N - 1];

		for (int j = N - 2; j >= 0; j--)
		{
			if (arr[j] < x)
			{
				answer += x - arr[j];
			}
			else
				x = arr[j];
		}

		std::cout << "#" << i+1 << " " << answer << endl;
	}
}