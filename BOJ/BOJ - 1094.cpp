#include<iostream>
using namespace std;

int main()
{
	int x; // 64 = 2의 6승
	int answer = 0;
	std::cin >> x;

	//이진수로 바꿔서 1의 갯수를 구해보자
	for (int i = 0; x > 0; i *= 10)
	{
		if (x % 2 == 1)
			answer++;
		x /= 2;
	}
	
	std::cout << answer << endl;
}