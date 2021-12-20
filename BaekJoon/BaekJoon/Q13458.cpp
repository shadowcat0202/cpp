#include "mathematical_interpretation.h"

void Q13458::run() {
	std::cin >> exam_room;
	if (exam_room < 1 || exam_room > INF)
		exit(-1);

	tester = new int[exam_room];
	for (int i = 0; i < exam_room; i++) {
		std::cin >> tester[i];
	}

	std::cin >> master >> sub;
	if (master<1 || sub>INF || sub<1 || sub>INF) {
		exit(-1);
	}


	for (int i = 0; i < exam_room; i++) {
		tester -= master;
		total_viewer++;
		if (tester[i] > 0) {
			total_viewer += tester[i] % sub == 0 ? tester[i] / sub : tester[i] / sub + 1;
		}
	}
	std::cout << total_viewer << "\n";


	delete[] tester;
}