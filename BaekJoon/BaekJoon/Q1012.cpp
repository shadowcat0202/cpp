#include "Graph_theory.h"

void Q1012::run() {
	std::cin >> T;
	for (int t = 0; t < T; t++) {
		std::cin >> M >> N >> K;

		//동적 할당
		/*
		type** array = new type[N][M];
		이따구로는 못한다
		*/
		field = new bool* [N];
		for (int count = 0; count < N; count++) {
			field[count] = new bool[M] {false,};
		}

		visited = new bool* [N];
		for (int count = 0; count < N; count++) {
			visited[count] = new bool[M] {false,};
		}

		//배추 심기
		for (int k = 0; k < K; k++) {
			int x, y;
			std::cin >> x >> y;
			field[y][x] = true;
		}
		
		
		DFS_solution();
		std::cout << result << "\n";

		result = 0;

		//동적 할당 해제
		for (int count = 0; count < N; count++) {
			delete[] field[count];
		}
		delete[] field;

		for (int count = 0; count < N; count++) {
			delete[] visited[count];
		}
		delete[] visited;
	}
}

void Q1012::DFS_solution() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (field[y][x] == true && !visited[y][x]) {
				//구역 찾기
				result++;
				DFS(y, x);				
			}
		}
	}
}
void Q1012::DFS(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)	continue;

		if (field[next_y][next_x] == true && !visited[next_y][next_x]) {
			DFS(next_y, next_x);
		}
	}
}

void Q1012::BFS() {

}
