#include<iostream>
#include<algorithm>
bool check[16] = { false, };
char alpha[16];
char ans[16];
int l, c;

using namespace std;

bool aeiou() {
	int a = 0, b = 0;
	for (int i = 0; i < l; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
			a++;
		else
			b++;
	}
	if (a >= 1 && b >= 2)
		return true;
	else
		return false;
}

void recur(int tmp, int count) {
	if (count == l) {
		if (aeiou()) {
			for (int i = 0; i < l; i++)
				cout << ans[i];
			cout << "\n";
		}
		return;
	}

	for (int i = tmp; i <= c; i++) {
		if (check[i] == false) {
			check[i] = true;
			ans[count] = alpha[i];
			recur(i, count + 1);
			check[i] = false;
		}
	}


}


int main() {
	cin >> l >> c;

	for (int i = 1; i <= c; i++)
		cin >> alpha[i];
	sort(alpha + 1, alpha + c + 1);

	recur(1, 0);

	return 0;
}