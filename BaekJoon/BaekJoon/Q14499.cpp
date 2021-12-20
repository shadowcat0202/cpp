#include "mathematical_interpretation.h"
#include "queue"


bool Q14499::roll(int type) {
	bool OK = true;
	int buf = dice.bottom;

	switch (type) {
	case 1:	//동쪽		
		if (dice.x + 1 >= M) {
			OK = false;
			break;
		}
		dice.x++;
		dice.bottom = dice.east;
		dice.east = dice.top;
		dice.top = dice.west;
		dice.west = buf;
		break;
	case 2:	//서쪽
		if (dice.x - 1 < 0) {
			OK = false;
			break;
		}
		dice.x--;
		dice.bottom = dice.west;
		dice.west = dice.top;
		dice.top = dice.east;
		dice.east = buf;
		break;
	case 3:	//북쪽
		if (dice.y - 1 < 0) {
			OK = false;
			break;
		}
		dice.y--;
		dice.bottom = dice.north;
		dice.north = dice.top;
		dice.top = dice.south;
		dice.south = buf;
		break;
	case 4:	//남쪽
		if (dice.y + 1 >= N) {
			OK = false;
			break;
		}
		dice.y++;
		dice.bottom = dice.south;
		dice.south = dice.top;
		dice.top = dice.north;
		dice.north = buf;
		break;
	default:
		break;
	}
	return OK;
}
void Q14499::run() {
	int command;
	std::cin >> N >> M >> dice.y >> dice.x >> command;

	board = new int* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
		for (int j = 0; j < M; j++) {
			std::cin >> board[i][j];
		}
	}
	

	for (int i = 0; i < command; i++) {
		int type;
		std::cin >> type;

		if (roll(type) == false)	continue;

		//보드가 0일경우 주사위의 bottom의 숫자를 복사
		if (board[dice.y][dice.x] == 0) {
			board[dice.y][dice.x] = dice.bottom;
		}
		else {
			dice.bottom = board[dice.y][dice.x];
			board[dice.y][dice.x] = 0;
		}

		std::cout << dice.top << "\n";
	}


	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	board = NULL;

}