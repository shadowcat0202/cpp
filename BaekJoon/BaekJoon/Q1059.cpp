#include "brute_force.h"
#include <algorithm>
#include <vector>
void Q1059::run() {
	std::cin >> L;
	std::vector<int> v(L+2);
	v[0] = 0;	//와 이거 에반데?
	v[L + 1] = 1000;
	for (int i = 1; i <= L; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	std::cin >> n;
	for (int i = 0; i < L+2; i++) {
		if (v[i] == n) {
			std::cout << 0 << "\n";
			break;
		}
		else{
			if (v[i] < n && n < v[i+1]) {
				int left, right;
				left = (n - v[i] - 1);
				right = v[i + 1] - n - 1;

				std::cout << (left * (right + 1) + right) << "\n";
				break;
			}
		}
	}

}

