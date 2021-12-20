#pragma once
#include <iostream>
#include <queue>
#include <vector>

class Q1026 {
	//https://www.acmicpc.net/problem/1026
	int N;
	std::priority_queue<int, std::vector<int>, std::greater<int>> arr_A;
	std::priority_queue<std::pair<int, int>> arr_B;
	int sort_arr[2][50];

public:
	void run();
};

class Q1205 {	//해결
	//Silver 5
	//https://www.acmicpc.net/problem/1205
	int N, chart_limit, my_score;
	//std::priority_queue<int> chart_pq;
	std::vector<int> v;

public:
	void run();

};

class Q1049 {	//해결
	//Silver 4
	//https://www.acmicpc.net/problem/1049
	int Broken_line, String_brands;
	std::vector<std::pair<int, int>> price_list_v;
	std::pair<int, int> min_price = {1e9, 1e9};

public:
	void run();
	void input();
};