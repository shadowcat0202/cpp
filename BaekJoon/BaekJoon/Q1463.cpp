#include "Dynamic_Programming.h"

void Q1463::make_dp(int n){
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)	dp[i] = std::min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)	dp[i] = std::min(dp[i], dp[i / 3] + 1);
	}
	
}

void Q1463::run() {
	int n;
	std::cin >> n;

	dp = new int[n + 1]{0,};
	dp[1] = 0;

	make_dp(n);
	std::cout << dp[n] << "\n";
	
	delete[] dp;
	dp = NULL;
}