#include "brute_force.h"
#include <queue>

void Q12100::move(int d) {
	std::queue<int> q;
	
	switch (d) {
		//╩С
	case 0:
		
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if(map[y][x])	q.push(map[y][x]);
				map[y][x] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (map[idx][x] == 0)			map[idx][x] = data;
				else if (map[idx][x] == data)	map[idx++][x] *= 2;
				else 							map[++idx][x] = data;
			}
		}

		
		break;
		//го
	case 1:
		for (int x = 0; x < N; x++) {
			for (int y = N-1; y >= 0; y--) {
				if (map[y][x])	q.push(map[y][x]);
				map[y][x] = 0;
			}

			int idx = N-1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (map[idx][x] == 0)			map[idx][x] = data;
				else if (map[idx][x] == data)	map[idx--][x] *= 2;
				else 							map[--idx][x] = data;
			}
		}
		break;
		//аб
	case 2:
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x])	q.push(map[y][x]);
				map[y][x] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (map[y][idx] == 0)			map[y][idx] = data;
				else if (map[y][idx] == data)	map[y][idx++] *= 2;
				else 							map[y][++idx] = data;
			}
		}
		break;
		//©Л
	case 3:
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x >= 0; x--) {
				if (map[y][x])	q.push(map[y][x]);
				map[y][x] = 0;
			}

			int idx = N-1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (map[y][idx] == 0)			map[y][idx] = data;
				else if (map[y][idx] == data)	map[y][idx--] *= 2;
				else 							map[y][--idx] = data;
			}
		}
		break;		
	}
	
}

void Q12100::DFS(int cnt) {
	if (cnt == 5) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				maxnumber = std::max(maxnumber, map[y][x]);
			}
		}
		return;
	}

	int** copymap;
	copymap = new int*[N];
	for (int i = 0; i < N; i++) {
		copymap[i] = new int[N];
		for (int j = 0; j < N; j++) {
			copymap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		move(i);
		DFS(cnt + 1);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				map[y][x] = copymap[y][x];
			}
		}
	}


	for (int i = 0; i < N; i++) {
		delete[] copymap[i];
	}
	delete[] copymap;
	copymap = NULL;
}

void Q12100::run() {
	std::cin >> N;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}
	
	DFS(0);
	std::cout << maxnumber << "\n";

	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;
}