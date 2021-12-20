#include <iostream>
#include "data_structure.h"
void Q3190::run() {
	input();
	//���� ��ġ (1,1)
	snake.push_back({ 1,1 });
	apple_map[1][1] = -1;
	dir = 0;	//���� ���� ������

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
			dir = (dir + 3) % 4;	//�������� 90��
			
		}else if (c == 'D') {
			dir = (dir + 1) % 4;	//�������� 90��
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
	//������ ����°�(������ ���� Ȯ�� ������ �ȱ׷��� ���� Ȯ�� �κп��� out of range���´�)
	if (ny < 1 || nx < 1 || ny > N || nx > N || apple_map[ny][nx] == -1) {
		return false;
	}

	if (apple_map[ny][nx] == 0) {	//����� ������ ������ ����ֱ�
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