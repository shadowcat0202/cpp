#include "non_classification.h"
#include <algorithm>

void Q1049::run() {
	input();

	int min;
	int pack = Broken_line / 6;
	int remain = Broken_line % 6;

	for (int i = 0; i < String_brands; i++) {
		//��Ű���� ���������� ���� ���� �ݾ� ��
		min = (price_list_v[i].first < price_list_v[i].second * 6) 
			? price_list_v[i].first : price_list_v[i].second * 6;

		min_price.first = (min < min_price.first) ? min : min_price.first;

		//��Ű���� �����ϰ� ���� ��Ÿ���� ������ �������� ��Ű���� �������� ���� ���� �ݾ� ��
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
