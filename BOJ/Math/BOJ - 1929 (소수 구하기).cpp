#include<iostream>
#include<algorithm>
using namespace std;
int arr[100];

bool multi2(int a) {
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == a) {
			arr[i] = 0;
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> value[100];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int index = 0;
	

	value[index].push_back(arr[0]);
	arr[0] = 0;

	bool check = false;
	int i = 0;
	while (!check) {
		if (value[i] % 3 == 0) {
			int a = value[i] / 3;
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] == a) {
					arr[i] = 0;
					value[index].push_back(arr[i]);
					break;
				}
			}
		}
		else if (multi2(value[i] * 2)) {
			value[index].push_back(arr[i]);
		}
		else {
			index++;
			check = true;
		}
		i++;
	}
	
	for (int i = 0; i < value.size(); i++) {
		cout << value[i] << " ";
	}
	
	return 0;
}