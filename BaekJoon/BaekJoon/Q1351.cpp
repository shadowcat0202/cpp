#include "data_structure.h"


long long Q1351::memo(std::map<long long, long long>& dp, long long i)
{
	if (dp.count(i))	return dp[i];
	return dp[i] = memo(dp, i / P) + memo(dp, i / Q);
}

void Q1351::run() {
	std::cin >> N >> P >> Q;
	std::map<long long, long long> dp;
	dp[0] = 1;
	std::cout << memo(dp, N) << "\n";
}