#include "Dynamic_Programming.h"

void Q2579::make_dp() {
	dp[1] = stairs[1];
	dp[2] = std::max(stairs[1], stairs[1] + stairs[2]);
	dp[3] = std::max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
	
	for (int i = 4; i <= N; i++) {
		dp[i] = std::max(stairs[i] + dp[i - 2], stairs[i] + stairs[i - 1] + dp[i - 3]);
	}
}
void Q2579::run() {
	std::cin >> N;

	stairs = new int[N + 1];

	dp = new int[N+1];

	for (int i = 1; i <= N; i++) {
		std::cin >> stairs[i];
	}

	make_dp();

	std::cout << dp[N] << "\n";

	delete[] dp;
	dp = NULL;
}