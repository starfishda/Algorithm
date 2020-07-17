#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cal_method[4];
vector<int> int_vec;
vector<int> answer_vec;
vector<int> now_cal_method;

int calculator() {
	int answer = 0;

	// �����ڿ� ���� �ٸ� ������ �������ش�.
	answer = int_vec[0];
	for (int i = 0; i < N - 1; i++) {
		switch (now_cal_method[i]) {
		case 0:
			answer += int_vec[i + 1];
			break;
		case 1:
			answer -= int_vec[i + 1];
			break;
		case 2:
			answer *= int_vec[i + 1];
			break;
		case 3:
			answer /= int_vec[i + 1];
			break;
		default:
			break;
		}
	}

	return answer;
}

void dfs(int depth) {
	// ������ �������̸� ���� ���Ѵ�.
	if (depth == N - 1) {
		int now_val = calculator();
		answer_vec.push_back(now_val);
	}
	else {
		// �߰� �����̸� ���� ���̸� ���Ѵ�.
		for (int i = 0; i < 4; i++) {
			if (cal_method[i]) {
				cal_method[i]--;
				now_cal_method.push_back(i);

				dfs(depth + 1);

				cal_method[i]++;
				now_cal_method.pop_back();
			}
		}
	}

}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int sub;
		scanf("%d", &sub);
		int_vec.push_back(sub);
	}

	for (int i = 0; i < 4; i++)
		cin >> cal_method[i];

	// dfs�� �̿��ؼ� ���� �����ڵ��� �����Ѵ�.
	now_cal_method.clear();

	dfs(0);

	// ����
	sort(answer_vec.begin(), answer_vec.end());

	// �� ���
	printf("%d\n%d", answer_vec.back(), answer_vec[0]);

	return 0;
}