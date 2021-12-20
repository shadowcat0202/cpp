#include "Dynamic_Programming.h"

int Q2839::bag(int n) {
	if (n < 3)	return -1;

	int bigmax = n / big;
	//큰 묶음을 최대치에서 하나씩 줄여가면서 작은 묶음으로 남김없이 묶일때 까지
	while (bigmax >= 0) {
		int temp = n - (big * bigmax);	//큰 묶음으로 묶고 남는 개수
		if (temp % small == 0) {	//남은 개수를 작은 묶음으로 딱 맞아 떨어질때
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