#include "Graph_theory.h"
#include <string>
#include <conio.h>
void Q2178::run() {	
	std::cin >> N >> M;

	maze = new info*[N];
	for (int i = 0; i < N; i++) {
		maze[i] = new info[M];
	}
	char* getline = new char[M];
	for (int i = 0; i < N; i++) {
		std::string buf;
		std::cin >> buf;
		for (int j = 0; j < M; j++) {
			maze[i][j].road = buf[j] - '0';
			maze[i][j].visited = 0;
		}
	}

	maze[0][0].visited = 1;
	BFS();
	for (int i = 0; i < N; i++) {
		delete[] maze[i];
	}
	delete[] maze;

	maze = NULL;
}

void Q2178::BFS(){
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,1,0,-1 };
	std::queue<std::pair<int, int>> q;	//{y,x}
	q.push({ 0,0 });

	while (!q.empty()) {
		std::pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			std::pair<int, int> next = { now.first + dy[i], now.second + dx[i] };
			
			//미로 밖이면 패스
			if (next.first >= N || next.second >= M || next.first < 0 || next.second < 0)	continue;
			if (maze[next.first][next.second].visited > 0)	continue;	//방문여부
			if (maze[next.first][next.second].road == 0)	continue;	//벽
			
			maze[next.first][next.second].visited = maze[now.first][now.second].visited + 1;
			q.push(next);			
		}
	}
	std::cout << maze[N - 1][M - 1].visited << "\n";
}
