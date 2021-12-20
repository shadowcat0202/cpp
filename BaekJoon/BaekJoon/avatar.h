#pragma once
#include "iostream"
#include <queue>

class Q14890 { //해결
	//https://www.acmicpc.net/problem/14890
	int N, L;
	int result = 0;
	int** map;
public:
	void run();
	bool stairs(int row);
	void swap(int& a, int& b);
};
class Q15685 {	//미해결(드래곤 커브)
	//https://www.acmicpc.net/problem/15685
	int N;
	int x, y, d, g;
	bool** map;
	int curve[4][1025];
	std::pair<int, int> dir[4] = { {0,1},{-1,0},{0,-1},{1,0} };
public:
	int ans();
	void make_map(int x, int y, int d);
	void dragon();
	void run();
};

class Q1966 {	//해결
	//https://www.acmicpc.net/problem/1966
	int test_case;
	int N, print_num;

public:
	void run();
};

class Q2108 {	//해결?
	//https://www.acmicpc.net/problem/2108
	int N;
	long sum = 0;
	int* histogram = new int[8001]{0,};
	std::priority_queue<int, std::vector<int>, std::less<int>> left;	//내림차순
	std::priority_queue<int, std::vector<int>, std::greater<int>> right;	//오름차순
	int mid;
public:
	void run();
};

class Q10157 {	//해결
	struct coordinate {
		int x;
		int y;
	};
	//Silver 4
	//https://www.acmicpc.net/problem/10157
	int C, R, N;

private:
	void input();
	void show_coordinate(int(*pos)[2]);
	void brute_force_solution();
	void mathematical_interpretation();
	int border_colc(const struct coordinate pos[]);
public:
	void run();
	
};