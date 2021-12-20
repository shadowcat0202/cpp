#include "avatar.h"

void Q14890::swap(int& a, int& b) {
	int buf = a;
	a = b;
	b = buf;
}

bool Q14890::stairs(int row) {
	for (int i = 0; i < N; i++) {
		std::cout << map[row][i] << " ";
	}
	std::cout << "\t";
	
	int land = 0;
	int bf = 0;
	for (int i = 1; i < N; i++) {
		if (std::abs(map[row][bf] - map[row][i]) >= 2)	return false;	//높이 2이상
		if (map[row][bf] == map[row][i]) {
			land++;
			bf = i;
			continue;
		}


		if (map[row][bf] - map[row][i] == 1) {	//하강하는 경우
			for (int j = 1; j < L; j++) {
				if (map[row][i] != map[row][i+j] || i+j >= N)	return false;
			}
			bf += L;
			i = bf;
			land = -1;
		}
		else if (map[row][bf] - map[row][i] == -1) {	//상승하는 경우
			land++;
			if (land < L)	return false;
			land = 0;
			bf = i;
		}

	}
	return true;
}
void Q14890::run() {
	std::cin >> N >> L;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		if (stairs(i)) {
			result++;
			std::cout << "ture\n";
		}
		else {
			std::cout << "\n";
		}
	}

	std::cout << "대칭\n";
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			swap(map[i][j], map[j][i]);
		}
	}

	for (int i = 0; i < N; i++) {
		if (stairs(i)) {
			result++;
			std::cout << "ture\n";
		}
		else {
			std::cout << "\n";
		}
	}

	std::cout << result << "\n";

	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;

}