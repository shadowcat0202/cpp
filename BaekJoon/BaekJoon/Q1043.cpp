#include <iostream>
#include "sstream"
#include "data_structure.h"

void Q1043::run() {
	input();

	int res = Party_max;
	//기본 2중 vector라 for문도 2중
	for (const auto& people : party) {
		bool flag = false;
		for (const auto& person : people) {
			if (flag)	break;
			for (const auto& know : Know) {
				//파티 참여자가 아는사람이면 해당 파티에서는 거짓말 못함
				if (Find(person) == Find(know)) {
					flag = true;
					break;
				}
			}
		}
		if (flag)	res--;
	}
	std::cout << res << "\n";
}

void Q1043::input() {
	//첫째줄
	std::cin >> Person_max >> Party_max;

	//둘째줄
	int K;
	std::cin >> K;

	while (K--) {
		int buf;
		std::cin >> buf;
		Know.push_back(buf);
	}

	//부모 배열 초기화
	for (int i = 1; i <= Person_max; i++) {
		parents[i] = i;
	}

	//셋째줄(각 파티에 관한 인원)
	party.resize(50);

	for (int i = 0; i < Party_max; i++) {
		int p;
		std::cin >> p;

		int num;
		int prev;
		for (int j = 0; j < p; j++) {
			if (j > 0) {
				prev = num;
				std::cin >> num;
				Union(prev, num);
			}
			else
				std::cin >> num;

			party[i].push_back(num);
		}
	}

}
int Q1043::Find(int p)
{
	if (parents[p] == p)	return p;
	return p = Find(parents[p]);
}

void Q1043::Union(int p1, int p2)
{
	p1 = Find(p1);
	p2 = Find(p2);
	parents[p1] = p2;	
}
