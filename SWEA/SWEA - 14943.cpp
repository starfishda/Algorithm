#include<iostream>
#include<cmath> // abs = Àý´ë°ª

using namespace std;

int main()
{
	int N;
	long long answer = 0, current = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long value;
		cin >> value;
		answer += (long long)abs(current);
		cout << answer << endl;
		current += value;
	}
}