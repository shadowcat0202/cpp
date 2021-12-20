#include "Dynamic_Programming.h"

int Q2839::bag(int n) {
	if (n < 3)	return -1;

	int bigmax = n / big;
	//ū ������ �ִ�ġ���� �ϳ��� �ٿ����鼭 ���� �������� ������� ���϶� ����
	while (bigmax >= 0) {
		int temp = n - (big * bigmax);	//ū �������� ���� ���� ����
		if (temp % small == 0) {	//���� ������ ���� �������� �� �¾� ��������
			return bigmax + (temp / small);
		}
		bigmax--;
	}
	return -1;
}

void Q2839::run() {
	int n = 0;
	std::cin >> n;
	std::cout << bag(n) << "\n";
}