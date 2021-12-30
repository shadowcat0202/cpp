#include "data_structure.h"


void Q1781::run() {
	std::cin >> N;
	v = std::vector<std::pair<int, int>>(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i].first >> v[i].second;
	}

	std::sort(v.begin(), v.end());

	//구조체 벡터 정렬 방법(처음 생각했던 방법)
	/*
	std::sort(v.begin(), v.end(), [](const data& p1, const data& p2) {
		if (p1.cup > p2.cup)	return true;
		else if (p1.cup == p2.cup) {
			if (p1.dead_line < p2.dead_line) return true;
		}
		return false;
		});
		*/

	for (int i = 0; i < N; i++) {
		pq.push(-v[i].second);
		if (pq.size() > v[i].first)	pq.pop();
	}
	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}

	std::cout << -ans << "\n";

}