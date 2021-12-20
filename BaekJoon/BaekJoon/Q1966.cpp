#include "avatar.h"
#include <queue>

void Q1966::run() {

	std::cin >> test_case;
	int* ans = new int[test_case] {0,};

	for (int i = 0; i < test_case; i++) {
		std::cin >> N >> print_num;
		
		std::queue<std::pair<int, bool>> q;
		std::priority_queue<int> pq;
		for (int j = 0; j < N; j++) {
			int paper;
			std::cin >> paper;
			pq.push(paper);

			if (j == print_num) {
				q.push(std::make_pair(paper, true));
			}
			else {
				q.push(std::make_pair(paper, false));
			}
		}


		while (true) {
			std::pair<int, bool> now = q.front();

			if (now.first < pq.top()) {
				q.push(now);
				q.pop();
			}
			else {
				if (now.second == true) {
					q.pop();
					pq.pop();
					ans[i]++;
					break;
				}
				else {
					pq.pop();
					q.pop();
					ans[i]++;
				}
			}
		}
		std::cout << ans[i] << "\n";
	}
}