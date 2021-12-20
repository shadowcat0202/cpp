#include "Graph_theory.h"
#include <conio.h>
#include <Windows.h>

void Q13460::show(bead& b) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b.ry == i && b.rx == j)	std::cout << "R";
			else if (b.by == i && b.bx == j)	std::cout << "B";
			else {
				if (map[i][j] == 'R' || map[i][j] == 'B') {
					std::cout << ".";
				}
				else {
					std::cout << map[i][j];
				}
				
			}
		}
		std::cout << "\n";
	}
	std::cout << b.tilt << "\n";

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			system("cls");
			break;
		}
	}
}

void Q13460::move(int& y, int& x, int& t, int& i) {
	while (map[y + dir[i].first][x + dir[i].second] != '#' && map[y][x] != 'O') {
		y += dir[i].first;
		x += dir[i].second;
		t += 1;
	}
}

void Q13460::BFS() {
	while (!q.empty()) {
		bead cur = q.front();
		q.pop();		

		show(cur);


		if (cur.tilt >= 10)	break;

		for (int i = 0; i < 4; i++) {
			
			int rc = 0, bc = 0, nt = cur.tilt + 1;
			bead next = { cur.ry, cur.rx, cur.by, cur.bx, nt};

			move(next.ry, next.rx, rc, i);
			move(next.by, next.bx, bc, i);

			if (map[next.by][next.bx] == 'O')	continue;
			if (map[next.ry][next.rx] == 'O') {
				std::cout << nt << "\n";
				return;
			}
			
			//±¸½½ÀÌ °ãÄ¥°æ¿ì
			if (next.ry == next.by && next.rx == next.bx) {
				if (rc > bc)	next.ry -= dir[i].first, next.rx -= dir[i].second;
				else			next.by -= dir[i].first, next.bx -= dir[i].second;
			}

			if (visited[next.ry][next.rx][next.by][next.bx])	continue;
			visited[next.ry][next.rx][next.by][next.bx] = true;
			q.push(next);

		}
	}
	std::cout << "-1";
}

void Q13460::run() {
	std::cin >> N >> M;

	map = new char* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new char[M];
	}

	visited = new bool*** [10];	//visited[R|B][y][x]
	for (int i = 0; i < 10; i++) {
		visited[i] = new bool** [10];
		for (int j = 0; j < 10; j++) {
			visited[i][j] = new bool*[10];
			for (int k = 0; k < 10; k++) {
				visited[i][j][k] = new bool[10]{false,};
			}
		}
	}


	int ry=0, rx=0, by=0, bx=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 'R') {
				ry = i; rx = j;
			}
			else if (map[i][j] == 'B') {
				by = i; bx = j;
			}
		}
	}

	q.push({ry, rx, by, bx, 0});
	visited[ry][rx][by][bx] = true;
	BFS();



	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				delete[] visited[i][j][k];
			}
			delete[] visited[i][j];
		}
		delete[] visited[i];
	}
	delete[] visited;
	visited = NULL;


	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;
	map = NULL;

}