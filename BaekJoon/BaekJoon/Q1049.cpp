#include "non_classification.h"
#include <algorithm>

void Q1049::run() {
	input();

	int min;
	int pack = Broken_line / 6;
	int remain = Broken_line % 6;

	for (int i = 0; i < String_brands; i++) {
		//패키지를 구매했을때 가장 적은 금액 비교
		min = (price_list_v[i].first < price_list_v[i].second * 6) 
			? price_list_v[i].first : price_list_v[i].second * 6;

		min_price.first = (min < min_price.first) ? min : min_price.first;

		//패키지로 구매하고 남은 기타줄을 낱개로 구매할지 패키지로 구매할지 가장 적은 금액 비교
		min = (price_list_v[i].first < price_list_v[i].second * remain)
			? price_list_v[i].first : price_list_v[i].second * remain;
		
		min_price.second = (min < min_price.second) ? min : min_price.second;
	}

	std::cout << min_price.first * pack + min_price.second;
}

void Q1049::input(){
	std::cin >> Broken_line >> String_brands;
	for (int i = 0; i < String_brands; i++) {
		int pakage, single;
		std::cin >> pakage >> single;
		price_list_v.push_back(std::make_pair(pakage, single));
	}
	std::sort(price_list_v.begin(), price_list_v.end(), [](auto& left, auto& right) {
		return left.second < right.second;
	});

	/*for (int i = 0; i < String_brands; i++) {
		std::cout << price_list_v[i].first << "\t" << price_list_v[i].second << "\n";
	}*/
}
