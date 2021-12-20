#include "my_test.h"

void my_test::run(){
	int N;
	std::cin >> N;

	std::vector<int>* v = new std::vector<int>[N + 1];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v[i].push_back(j*i);
		}
	}
	vector_pointer(v, N, N);

	delete[] v;
	v = NULL;
}

void my_test::vector_pointer(std::vector<int>* v, int row, int col){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}
