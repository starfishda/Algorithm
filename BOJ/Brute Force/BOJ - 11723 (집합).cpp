#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);//����� �ӵ� ���
	cin.tie(0);

	bool check[21];
	memset(check, false, sizeof(check));
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		string str;
		cin >> str;

		if (str == "add") {
			cin >> a;
			check[a] = true;
		}
		else if (str == "remove") {
			cin >> a;
			check[a] = false;
		}
		else if (str == "toggle") {
			cin >> a;
			check[a] ? (check[a] = false) : (check[a] = true);
		}
		else if (str == "check") {
			cin >> a;
			check[a] ? (cout << "1\n") : (cout << "0\n");
		}
		else if (str == "all") { //1~20���� ä���
			memset(check, true, sizeof(check));
		}
		else { // empty�� ���
			memset(check, false, sizeof(check));
		}
	}
	return 0;
}