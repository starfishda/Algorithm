#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
bool button[10];
int cnt = 0;

int valid(string value) {
	for (int i = 0; i < value.size(); i++) {
		if (!button[value[i] - '0'])
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	int ans = 1000001;

	int m;
	cin >> m;

	for (int i = 0; i < 10; i++)
		button[i] = true;

	for (int i = 0; i < m; i++) {
		int check;
		cin >> check;
		button[check] = false;
	}

	//1. 100에서 +, -로 이동하는 경우
	ans = min(ans, abs(100 - n));
	
	//2. 버튼을 누른후 +,-로 이동하는 경우
	for (int i = 0; i < 999999; i++) {
		string num = to_string(i);
		cnt = valid(num);
		if (cnt == 1)
			ans = min(ans, int(abs(i - n) + num.size()));
	}

	cout << ans;
	return 0;
}