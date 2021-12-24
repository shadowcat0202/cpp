#pragma warning(disable:4996)
#include <iostream>
//#include "avatar.h"	//구현
//#include "mathematical_interpretation.h"	//수학
//#include "brute_force.h"	//부르드 포스
//#include "Graph_theory.h"	//그래프 이론
//#include "Dynamic_Programming.h"	//동적 프로그래밍
//#include "non_classification.h"	//미분류 문제
#include "sort.h"	//정렬?
//#include "data_structure.h"	//자료구조
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
	//std::cin std::cout 입출력 속도 증가
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Q1517 problem;

	if (exists("input.txt")) {
		freopen("input.txt", "r", stdin);
		
		
		problem.run();
		
		fclose(stdin);
	}
	else {
		std::cout << "입력 파일이 없기 때문에 수동으로 전환\n";
		problem.run();
	}
	
}



//단위 테스트용 함수
void test() {
	std::cout << "test()\n";
	std::cout << "수정된 부분\n";
	std::cout << "나는 마스터\n";
}
int main(int argc, const char* argv[]) {
	boj();
	//test();
	return 0;
}