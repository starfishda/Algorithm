#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string N;
	int B, sum = 0;

	cin >> N >> B;
	int tmp = 1;

	for (int i = N.size() - 1; i >= 0; i--) {
		int num;
		if (N[i] >= '0' && N[i] <= '9')
			num = N[i] - '0';
		else
			num = N[i] - 'A' + 10;

		num *= tmp;
		sum += num;
		tmp *= B;
	}

	cout << sum;

	return 0;
}