#include <iostream>

#include <string>
using namespace std;

bool arr[1000001];

int main(void) {

	for (int i = 0; i <= 1000000; i++) {
		arr[i] = true;
	}
	arr[1] = false;
	
	for (int i = 2; i <= 1000000; i++) { // �Ҽ� ���ϱ�
		if (arr[i]) {
			for (int j = 2 * i; j <= 1000000; j += i) {
				arr[j] = false;
			}
		}
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) { // �׽�Ʈ���̽� ��
		int n; // n�� ������ ¦��
		cin >> n;
		
		int cnt = 0;
		for (int j = n / 2; j >= 2; j--) {
			if (arr[j] && arr[n - j])
				cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}