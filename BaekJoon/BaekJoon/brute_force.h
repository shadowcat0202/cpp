#pragma once
#include <iostream>

class Q12100 {
	//https://www.acmicpc.net/problem/12100
	int N;
	int** map;
	int maxnumber;

public:
	void DFS(int cnt);
	void move(int d);
	void run();

};

class Q14500 {
	//https://www.acmicpc.net/problem/14500
	int N, M;
	int** map;
	bool** visited;
	int result = -2e9;
	std::pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

public:
	void DFS(int y, int x, int cnt, int sum);
	void findRemainder(int y, int x);
	void run();
};

class Q1059 {	//silver 5
	//https://www.acmicpc.net/problem/1059
	int L, n;
public:
	void run();
};