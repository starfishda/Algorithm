#include<iostream>
using namespace std;

int main()
{
	int x; // 64 = 2�� 6��
	int answer = 0;
	std::cin >> x;

	//�������� �ٲ㼭 1�� ������ ���غ���
	for (int i = 0; x > 0; i *= 10)
	{
		if (x % 2 == 1)
			answer++;
		x /= 2;
	}
	
	std::cout << answer << endl;
}