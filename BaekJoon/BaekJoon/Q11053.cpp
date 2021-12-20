#include "Dynamic_Programming.h"


int Q11053::make_dp() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		//인터넷에 답이라고 적어놓은 사람들꺼 보면 j < N 이라고 많이 하는데
		//기준점임 i까지만 돌리는거랑 차이가 없다 결국 시간 낭비
		//j를 i까지만 돌리면 시간이 4ms -> 0ms로 감소
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
