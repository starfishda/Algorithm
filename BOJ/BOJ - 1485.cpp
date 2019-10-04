#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

P p[4];

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int answer = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> p[j].first >> p[j].second;
		}
		sort(p, p + 4);

		int a, b, c, d;//네 변의 길이

		a = pow(p[1].first - p[0].first, 2) + pow(p[1].second - p[0].second, 2);
		b = pow(p[2].first - p[0].first, 2) + pow(p[2].second - p[0].second, 2);
		c = pow(p[3].first - p[1].first, 2) + pow(p[3].second - p[1].second, 2);
		d = pow(p[3].first - p[2].first, 2) + pow(p[3].second - p[2].second, 2);

		if (a == b && a == c && a == d) {

			int e, f;

			//대각선
			e = pow(p[3].first - p[0].first, 2) + pow(p[3].second - p[0].second, 2);
			f = pow(p[2].first - p[1].first, 2) + pow(p[2].second - p[1].second, 2);

			if (e == f)
				answer = 1;
			else
				answer = 0;
		}
		else
			answer = 0;

		cout << answer << endl;
	}
	return 0;
}