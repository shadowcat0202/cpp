#include <iostream>
#include "data_structure.h"
void Q3190::run() {
	input();
	//시작 위치 (1,1)
	snake.push_back({ 1,1 });
	apple_map[1][1] = -1;
	dir = 0;	//시작 방향 오른쪽

	while (!move_q.empty()) {
		int move_dis = move_q.front().first;
		char c = move_q.front().second;
		move_q.pop();			
		while (play_time < move_dis) {
			if (!move()) {
				std::cout << play_time + 1;
				del();
				return;
			}
			play_time++;
		}
		if (c == 'L') {
			dir = (dir + 3) % 4;	//왼쪽으로 90도
			
		}else if (c == 'D') {
			dir = (dir + 1) % 4;	//왼쪽으로 90도
		}			
	}
	while (true) {
		if (!move()) {
			std::cout << play_time + 1;
			del();
			return;
		}
		play_time++;
	}
	del();
	return;

}


bool Q3190::move(){
	int ny = snake.front().first + dy[dir];
	int nx = snake.front().second + dx[dir];
	//범위를 벗어나는가(범위를 먼저 확인 해주자 안그러면 몸통 확인 부분에서 out of range나온다)
	if (ny < 1 || nx < 1 || ny > N || nx > N || apple_map[ny][nx] == -1) {
		return false;
	}

	if (apple_map[ny][nx] == 0) {	//사과가 없으면 꼬리만 당겨주기
		apple_map[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}

	apple_map[ny][nx] = -1;
	snake.push_front({ ny,nx });
	return true;
}

void Q3190::del() {
	for (int i = 0; i <= N; i++) {
		delete[] apple_map[i];
	}
	delete[] apple_map;
}

void Q3190::input() {
	std::cin >> N;
	std::cin >> K;

	apple_map = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		apple_map[i] = new int[N + 1]{ 0, };
	}

	for (int i = 0; i < K; i++) {
		int y, x;
		std::cin >> y >> x;
		apple_map[y][x] = 1;
	}

	std::cin >> L;
	for (int i = 0; i < L; i++) {
		int n;
		char d;
		std::cin >> n >> d;
		move_q.push({ n,d });
	}
}