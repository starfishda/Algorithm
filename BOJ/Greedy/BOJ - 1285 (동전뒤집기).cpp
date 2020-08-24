#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int ans = 40000;
	int n;
	cin >> n;

	char map[20][20];

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
			map[i][j] = str[j];
	}

	for (int k = 0; k < (1 << n); k++) {
		int num = 0;
		for (int j = 0; j < n; j++) {
			int temp = 0;

			for (int i = 0; i < n; i++) {
				char a = map[i][j];

				if ((1 << i) & k)
				{
					if (a == 'T') a = 'H';
					else a = 'T';
				}

				if (a == 'T') temp++;
			}

			num += min(temp, n - temp);
		}

		ans = min(ans, num);
	}

	cout << ans;

	return 0;
}