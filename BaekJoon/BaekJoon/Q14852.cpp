#include "Dynamic_Programming.h"

void Q14852::make_dp() {
	//f(n) = f(n-2) + 2 * g(n-1)
	//g(n) = f(n-1) + f(n-2) + g(n-2)
	for (int i = 2; i <= N; i++) {
		dp_g[i] = ((dp_f[i - 1] + dp_f[i - 2]) % MOD + dp_g[i - 2]) % MOD;
		dp_f[i] = (dp_f[i - 2] + (2 * dp_g[i]) % MOD) % MOD;
	}
}

void Q14852::run() {
	std::cin >> N;
	dp_f = new int[N+1];
	dp_g = new int[N+1];


	dp_f[0] = 1; dp_f[1] = 2;
	dp_g[0] = 0; dp_g[1] = 1;

	make_dp();

	std::cout << dp_f[N] << "\n";


	delete[] dp_f, dp_g;

	dp_f = NULL;
	dp_g = NULL;
}
