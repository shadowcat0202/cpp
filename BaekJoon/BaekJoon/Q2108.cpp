#include "avatar.h"
#include <queue>

void Q2108::run() {
	int avg, middle, many, minmax;

	std::cin >> N;
	std::cin >> mid;
	histogram[mid+4000]++;
	for (int i = 2; i <= N; i++) {
		int num;
		std::cin >> num;
		histogram[num + 4000]++;	//ÃÖºó°ª
		sum += num;	//»ê¼úÆò±Õ

		if (mid > num) {
			left.push(num);
		}
		else {
			right.push(num);
		}

		if (i % 2 == 1) {
			while (left.size() > right.size()) {
				right.push(mid);
				mid = left.top();
				left.pop();
			}
			while (left.size() < right.size()) {
				left.push(mid);
				mid = right.top();
				right.pop();
			}
		}
	}
	avg = (int)round(sum / N);
	middle = mid;

	int most = -9999;
	bool non_first = false;
	int most_value = 0;

	for (int i = 0; i < 8001; i++) {
		if (histogram[i] == 0)	continue;
		if (histogram[i] == most) {
			if (non_first) {
				most_value = i - 4000;
				non_first = false;
			}
		}
		if (histogram[i] > most) {
			most = histogram[i];
			most_value = i - 4000;
			non_first = true;
		}
	}
	many = most_value;
		

	while (left.size() > 1) {
		left.pop();
	}
	while (right.size() > 1) {
		right.pop();
	}
	minmax = right.top() - left.top();


	std::cout << "»ê¼úÆò±Õ:" << avg << "\n";
	std::cout <<"Áß¾Ó°ª:" << middle << "\n";
	std::cout <<"ÃÖºó°ª:" << many << "\n";
	std::cout <<"ÃÖ´ë ÃÖ¼Ò Â÷:" << minmax << "\n";
	
}