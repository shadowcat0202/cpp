#include "brute_force.h"

void Q14500::DFS(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		result = sum > result ? sum : result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		std::pair<int, int> next;
		next.first = y + dir[i].first;
		next.second = x + dir[i].second;

		if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)	continue;

		if (visited[next.first][next.second] == true)	continue;

		visited[next.first][next.second] = true;
		DFS(next.first, next.second, cnt + 1, sum + map[next.first][next.second]);
		visited[next.first][next.second] = false;
	}
}

void Q14500::findRemainder(int y, int x) {
	int sum = 0;
	//ㅗ
	if (y - 1 >= 0 && x + 2 < M) {
		sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1];
		result = result < sum ? sum : result;
	}
	//ㅏ
	if (y + 2 < N && x + 1 < M) {
		sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1];
		result = result < sum ? sum : result;
	}
	//ㅜ
	if (y + 1 < N && x + 2 < M) {
		sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
		result = result < sum ? sum : result;
	}
	//ㅓ
	if (y + 2 < N && x - 1 >= 0) {
		sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1];
		result = result < sum ? sum : result;
	}
}
void Q14500::run() {
	std::cin >> N >> M;

	//map[기본|가로|세로][][]
	map = new int* [N];
	visited = new bool* [N];
	
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		visited[i] = new bool[M];		
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			DFS(i,j,1,map[i][j]);
			visited[i][j] = false;
			findRemainder(i, j);
		}
	}



	for (int i = 0; i < N; i++) {
		delete[] map[i], visited[i];
	}
	delete[] map, visited;
	map = NULL;

	std::cout << result << "\n";
}


