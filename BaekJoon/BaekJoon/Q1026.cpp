#include "non_classification.h"

void Q1026::run() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int buf;
		std::cin >> buf;
		arr_A.push(buf);	//������������ �����Ǵ� priority_queue �� �ֱ�
	}

	for (int i = 0; i < N; i++) {
		int buf;
		std::cin >> buf;
		arr_B.push(std::make_pair(buf, i));	//ū ���� ������ ���� ����
	}

	for(int i = 0; i < N; i++) {
		int buf_a = arr_A.top();
		arr_A.pop();
		std::pair<int, int> buf_b = arr_B.top();
		arr_B.pop();

		sort_arr[0][buf_b.second] = buf_a;
		sort_arr[1][buf_b.second] = buf_b.first;
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		result += (sort_arr[0][i] * sort_arr[1][i]);
	}

	std::cout << result << "\n";
}