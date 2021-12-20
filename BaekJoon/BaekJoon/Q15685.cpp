#include "avatar.h"

int Q15685::ans() {
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == true && map[i + 1][j] == true && map[i][j + 1] == true && map[i + 1][j + 1] == true)
				answer++;
		}
	}
	return answer;
}

void Q15685::make_map(int x, int y, int d) {
	int size = std::pow(2, g);
	for (int i = 0; i < size; i++) {
		x += dir[curve[d][i]].second;
		y += dir[curve[d][i]].first;
		if (x > -1 && x < 101 && y > -1 && y < 101) {
			map[y][x] = true;
		}
	}
}

void Q15685::dragon() {
	int curve_size = 0;
	curve[0][curve_size] = 0;
	curve[1][curve_size] = 1;
	curve[2][curve_size] = 2;
	curve[3][curve_size] = 3;
	curve_size++;
	for (int i = 0; i < 10; i++) {
		for (int j = curve_size - 1; j >= 0; j--) {
			for (int k = 0; k < 4; k++) {
				curve[k][curve_size] = (curve[k][j] + 1) % 4;
			}
			curve_size++;
		}
	}
}

void Q15685::run() {
	std::cin >> N;
	map = new bool* [101];
	for (int i = 0; i < 101; i++) {
		map[i] = new bool[101];
	}

	dragon();
	for (int i = 0; i < N; i++) {
		std::cin >> x >> y >> d >> g;
		make_map(x, y, d);
		map[y][x] = 1;	
	}
	std::cout << ans() << "\n";

	for (int i = 0; i < 101; i++) {
		delete[] map[i];
	}
	delete[] map;
	map = NULL;


}