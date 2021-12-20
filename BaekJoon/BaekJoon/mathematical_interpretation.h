#pragma once
#include <iostream>

class Q13458{
	//https://www.acmicpc.net/problem/13458
	const int INF = 1e6;
	int exam_room;
	int* tester;
	int master, sub;
	long long total_viewer = 0;

public:
	void run();
};

class Q14499 {
	//https://www.acmicpc.net/problem/14499
	struct Dice {
		int y = 0;
		int x = 0;
		int bottom = 0;
		int top = 0;
		int east = 0;
		int west = 0;
		int north = 0;
		int south = 0;

	};
	std::pair<int, int> dir[4] = { {0,1},{0,-1},{-1,0},{1,0} };	//µ¿ ¼­ ºÏ ³²
	int N, M;
	int** board;
	Dice dice;
public:
	bool roll(int type);
	void run();
};