#include "Dynamic_Programming.h"

void Q1149::run() {
	std::cin >> N;

	dp = new int* [3];
	for (int i = 0; i < 3; i++) {
		dp[i] = new int [N];
	}

	for (int i = 0; i < N; i++) {
		std::cin >> dp[0][i] >> dp[1][i] >> dp[2][i];
	}

	make_dp();

	std::cout << std::min(dp[0][N - 1], std::min(dp[1][N - 1], dp[2][N - 1])) << "\n";


	for (int i = 0; i < 3; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	dp = NULL;
	
}
void Q1149::make_dp() {
	for (int i = 1; i < N; i++) {
		dp[0][i] += std::min(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] += std::min(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] += std::min(dp[0][i - 1], dp[1][i - 1]);
	}

}