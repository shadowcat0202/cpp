#include <iostream>
#include "sstream"
#include "data_structure.h"

void Q1043::run() {
	input();

	int res = Party_max;
	//�⺻ 2�� vector�� for���� 2��
	for (const auto& people : party) {
		bool flag = false;
		for (const auto& person : people) {
			if (flag)	break;
			for (const auto& know : Know) {
				//��Ƽ �����ڰ� �ƴ»���̸� �ش� ��Ƽ������ ������ ����
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
	//ù°��
	std::cin >> Person_max >> Party_max;

	//��°��
	int K;
	std::cin >> K;

	while (K--) {
		int buf;
		std::cin >> buf;
		Know.push_back(buf);
	}

	//�θ� �迭 �ʱ�ȭ
	for (int i = 1; i <= Person_max; i++) {
		parents[i] = i;
	}

	//��°��(�� ��Ƽ�� ���� �ο�)
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
