#pragma warning(disable:4996)
#include <iostream>
//#include "avatar.h"	//����
//#include "mathematical_interpretation.h"	//����
//#include "brute_force.h"	//�θ��� ����
//#include "Graph_theory.h"	//�׷��� �̷�
//#include "Dynamic_Programming.h"	//���� ���α׷���
//#include "non_classification.h"	//�̺з� ����
#include "sort.h"	//����?
//#include "data_structure.h"	//�ڷᱸ��
//#include "my_test.h"

bool exists(const char* fileName) {
	FILE* fp;
	if ((fp = fopen(fileName, "r"))) {
		fclose(fp);
		return true;
	}
	return false;
}

void boj() {
	//std::cin std::cout ����� �ӵ� ����
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Q1517 problem;

	if (exists("input.txt")) {
		freopen("input.txt", "r", stdin);
		
		
		problem.run();
		
		fclose(stdin);
	}
	else {
		std::cout << "�Է� ������ ���� ������ �������� ��ȯ\n";
		problem.run();
	}
	
}



//���� �׽�Ʈ�� �Լ�
void test() {
	std::cout << "test()\n";
	std::cout << "������ �κ�\n";
	std::cout << "���� ������\n";
}
int main(int argc, const char* argv[]) {
	boj();
	//test();
	return 0;
}