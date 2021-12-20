#include "Dynamic_Programming.h"


int Q11053::make_dp() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		//���ͳݿ� ���̶�� ������� ����鲨 ���� j < N �̶�� ���� �ϴµ�
		//�������� i������ �����°Ŷ� ���̰� ���� �ᱹ �ð� ����
		//j�� i������ ������ �ð��� 4ms -> 0ms�� ����
		for (int j = 0; j < i; j++) {	
			if (sequence[i] > sequence[j]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}			
		}
		sum = std::max(sum, dp[i]);
	}
	return sum;
}

void Q11053::run() {
	std::cin >> N;
	sequence = new int[N];
	dp = new int[N] {1,};
	for (int i = 0; i < N; i++) {
		std::cin >> sequence[i];
	}

	std::cout << make_dp() << "\n";

	delete[] sequence, dp;
	sequence = NULL;
	dp = NULL;

}
