#include<iostream>

using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		long long N;
		cin >> N;
		long long arr[100];

		arr[0] = arr[1] = arr[2] = 1;

		for (int i = 3; i < N; i++)
		{
			arr[i] = arr[i - 3] + arr[i - 2];
		}

		cout << "#" << test_case << " " << arr[N-1] << endl;
	}

	return 0;
}