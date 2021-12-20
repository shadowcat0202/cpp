#include "Dynamic_Programming.h"

int Q1912::solution() {
	int answer = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		//2가지 방법(속도 차이는 없다)
		//1.		
		dp[i] = dp[i - 1] + arr[i] > arr[i] ? dp[i - 1] + arr[i] : arr[i];
		answer = dp[i] > answer ? dp[i] : answer;
		//2.
		/*dp[i] = std::max(arr[i], arr[i] + dp[i - 1]);
		answer = std::max(answer, dp[i]);*/
	}
	return answer;
}

void Q1912::run() {
	std::cin >> N;

	arr = new int[N];
	dp = new int[N];

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	std::cout << solution() << "\n";

	delete[] arr, dp;
	arr = NULL;
	dp = NULL;
}