#include<iostream>
#include <iomanip>
#include<algorithm>
#include<math.h>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	long double ans = 999999.0;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 

	for (int i = 0; i <= n - k; i++) { //시작 배열
		for (int j = k; i + j <= n; j++) {
			long double sum = 0;
			for (int a = i; a < i + j; a++) {
				sum += arr[a];
			}
			long double mean = sum / double(j);

			sum = 0;
			for (int a = i; a < i + j; a++) {
				sum += pow((arr[a] - mean), 2);
			}
			ans = min(ans, sqrt(sum / double(j)));
		}
	}
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;
}