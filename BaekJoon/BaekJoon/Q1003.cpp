#include "Dynamic_Programming.h"

int Q1003::fibonacci(int n) {
	if (n == 0 || n == 1) {
		return dp[n];
	}
	else if (dp[n] != 0) {
		return dp[n];
	}
	else {
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}

void Q1003::run() {
	int T;
	std::cin >> T;
	dp[1] = 1;
	for (int i = 0; i < T; i++) {
		int temp;
		std::cin >> temp;
		if (temp == 0) {
			std::cout << "1 0" << "\n";
		}
		else
			std::cout << fibonacci(temp -1) << " " << fibonacci(temp) << "\n";
	}
}

