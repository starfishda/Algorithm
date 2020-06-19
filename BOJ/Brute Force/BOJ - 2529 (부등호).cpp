#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>

using namespace std;
vector<char> arr;
vector<string> answer;
bool visited[10];
int n;

void dfs(int index, int count, string str) {
	if (count == n)
		answer.push_back(str);
	else {
		for (int i = 0; i <= 9; i++) {
			if (!visited[i]) {
				if (arr[count] == '<') {
					if (index >= i)
						continue;
				}
				else {
					if (index <= i)
						continue;
				}
				visited[i] = true;
				dfs(i, count + 1, str + to_string(i));
			}
		}
	}
	visited[index] = false;
}

int main() {
	cin >> n;

	// 부등호 입력
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i <= 9; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i, 0, to_string(i) + "");
	}


	cout << answer[answer.size() - 1] << "\n" << answer[0];
	return 0;
}