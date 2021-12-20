#include "sort.h"
#include <algorithm>


void Q1183::show_state(){
	
}

void Q1183::input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		std::cin >> A >> B;
		arr.push_back(A - B);
	}
}

void Q1183::run() {
	//ют╥б
	input();
	std::sort(arr.begin(), arr.end());

	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	if (N % 2 == 1)	std::cout << 1;
	else	std::cout << arr[N / 2] - arr[N / 2 - 1] + 1;
	
	
}