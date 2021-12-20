#include "avatar.h"

void Q10157::show_coordinate(int (*pos)[2]) {
	std::cout << pos[3][0] << "," << pos[0][0] << "\t" << pos[1][0] << "," << pos[3][0] << "\n";
	std::cout << pos[3][0] << "," << pos[2][0] << "\t" << pos[1][0] << "," << pos[2][0] << "\n";
	
	std::cout << "\n";
	
}

int Q10157::border_colc(const struct coordinate pos[]) {
	int length_x = pos[1].x - pos[0].x;
	int length_y = pos[1].y - pos[0].y;

	return 2 * (length_y + length_x);
}

void Q10157::brute_force_solution(){
	coordinate pos[2] = { {1,1}, {C,R} };
	coordinate result = { 1,1 };

	coordinate dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
	int d = 0;

	if (R * C >= N) {
		while (true) {
			int bc = border_colc(pos);
			if (N > bc) {	//남은 인원수가 테두리 한겹을 꽉채울수 있는 경우
				N -= bc;
				pos[0].x++;	pos[0].y++;
				pos[1].x--;	pos[1].y--;
			}
			else if (N == bc) {
				std::cout << pos[0].x + 1 << " " << pos[0].y << "\n";
				break;
			}
			else {
				result.x = pos[0].x;
				result.y = pos[0].y;

				while (N > 1) {
					coordinate npos = { result.x + dir[d].x, result.y + dir[d].y };
					if (npos.x < pos[0].x || npos.x > pos[1].x || npos.y < pos[0].y || npos.y > pos[1].y) {
						d = (d + 1) % 4;
						continue;
					}
					N--;
					result = npos;
				}
				std::cout << result.x << " " << result.y << "\n";
				break;
			}
		}
	}
	else {
		std::cout << 0 << "\n";
	}
	
	
}

void Q10157::mathematical_interpretation(){
	int remain_N = N;
	std::pair<int, int>result = { 1,1 };

	if (C * R < remain_N) {
		std::cout << 0 << "\n";
	}
	else if (C* R == remain_N) {
		result.first = (R % 2 == 0) ? R / 2 : (R + 1) / 2;
		result.second= (C % 2 == 0) ? C / 2 : (C + 1) / 2;
	}
	else {		
		int bigger = (C > R) ? C : R;
		bigger = (bigger % 2 == 0) ? bigger : bigger + 1;
		for (int i = 1; i < bigger / 2; i++) {
			int border = 2 * (C + R - 4 * (i - 1) - 2);
			if (border < remain_N) {
				remain_N -= border;
			}
			else if (border == remain_N) {
				result = std::make_pair(i + 1, i);
			}
			else {
				int abs_y = std::abs((C - (i - 1) - i));
				int abs_x = std::abs((R - (i - 1) - i));

				if (abs_y < remain_N) {
					remain_N -= abs_y;
				}
				else {
					result = std::make_pair(i, i + remain_N-1);
					break;
				}
				if (abs_x < remain_N) {
					remain_N -= abs_x;
				}
				else {
					result = std::make_pair(i + remain_N, i + abs_y-1);
					break;
				}
				if (abs_y < remain_N) {
					remain_N -= abs_y;
				}
				else {
					result = std::make_pair(i + abs_x, i + abs_y - remain_N-1);
					break;
				}
				if (abs_x < remain_N) {
					remain_N -= abs_y;
				}
				else {
					result = std::make_pair(i, i + abs_x - remain_N-1);
					break;
				}
			}
		}

		std::cout << result.first << " " << result.second << "\n";
	}
}

void Q10157::input() {
	std::cin >> C >> R;
	std::cin >> N;
}

void Q10157::run() {
	input();
	brute_force_solution();
	//mathematical_interpretation();
	

}