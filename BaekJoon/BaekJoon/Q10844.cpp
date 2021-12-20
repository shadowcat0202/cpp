#include "Dynamic_Programming.h"


int Q10844::solution() {
	dp[0] = 0;
	dp[1] = 9;
	for (int i = 2; i <= N; i++) {
		dp[i] = 2 * dp[i - 1] % MOD - (i-1);
	}

	return dp[N];	
}


void Q10844::run() {
	std::cin >> N;
	dp = new int[N + 1];

	std::cout << solution() << "\n";

	delete[] dp;
	dp = NULL;
}
