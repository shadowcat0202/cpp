#include "Dynamic_Programming.h"

void Q11057::uphill(int n){
	dp = new long long* [n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new long long[10]{ 0, };
	}

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][9] = 1;	//가장 앞자리가 9일 경우 경우의 수 1개
		for (int j = 8; j >= 0; j--) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % MOD;
		}
	}
}


void Q11057::run() {
	int temp = 0;
	std::cin >> temp;
	uphill(temp);
	std::cout << dp[temp][0] % MOD << "\n";
	for (int i = 0; i <= temp; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}

