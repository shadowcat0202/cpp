#pragma once
#include <iostream>
#include <vector>

//참고해서 해결 (무슨소리인지 이해 불가)
class Q1183 {	
	//Silver 4
	//https://www.acmicpc.net/problem/1183

	int N;
	std::vector<int> arr;	

private:
	void input();
	void show_state();
public:
	void run();
	//3 -5 4
};

//해결(시간복잡도 중시)
class Q1517{
	//Diamond 5
	//버블소트
	//https://www.acmicpc.net/problem/1517
	//그냥 풀면 O(N^2)
	//mergesort를 사용해 O(NlogN)으로 풀어야 시간 초과 안거림
	int N;
	long long ans = 0;
	std::vector<int> v;


private:
	void mergeSort(int start, int end);
	void merge(int start, int mid, int end, int left, int right);
public:
	void run();
};