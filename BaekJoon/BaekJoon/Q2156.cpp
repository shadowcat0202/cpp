#include "Dynamic_Programming.h"


int Q2156::solution() {	
	dp[0] = 0;
	arr[0] = 0;
	dp[1] = arr[1];

	for (int i = 1; i <= N; i++) {
		if (i == 2) {
			dp[2] = arr[1] + arr[2];
		}
		if (i > 2) {			
			dp[i] = std::max(dp[i - 1],std::max( dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
		}
	}
	return dp[N];
}
void Q2156::run() {
	std::cin >> N;
	arr = new int[N+1];
	dp = new int[N + 1]{0,};
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}


	std::cout << solution() << "\n";
	
	delete[] arr, dp;
	arr = NULL;
	dp = NULL;
}