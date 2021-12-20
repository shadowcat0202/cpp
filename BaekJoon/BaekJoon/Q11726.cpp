#include "Dynamic_Programming.h"
#define DIV 10007

void Q11726::make_dp() {
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;
	}
}

void Q11726::run() {
	std::cin >> N;
	dp = new int[N + 1]{0,};

	make_dp();

	std::cout << dp[N] << "\n";
	delete[] dp;
	dp = NULL;
}