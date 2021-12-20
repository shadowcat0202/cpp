#include "non_classification.h"
#include <algorithm>
void Q1205::run() {
	std::cin >> N >> my_score >> chart_limit;
	
	if (N == 0) {
		std::cout << 1 << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			int buf;
			std::cin >> buf;
			v.push_back(buf);
		}

		sort(v.begin(), v.end(), std::greater<int>());

		int rank = 1;
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] > my_score) {
				rank++;
			}
			else if(v[i] == my_score){
				rank = rank;				
			}
			else {
				count++;
				if (count >= chart_limit){
					rank = -1;
					std::cout << rank << "\n";
				}					
				else {
					std::cout << rank << "\n";
					break;
				}
			}
			if (count > chart_limit) {
				rank = -1;
				std::cout << rank << "\n";
			}
		}
	}	
}