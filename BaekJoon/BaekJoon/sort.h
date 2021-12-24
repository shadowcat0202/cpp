#pragma once
#include <iostream>
#include <vector>

//�����ؼ� �ذ� (�����Ҹ����� ���� �Ұ�)
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

//�ذ�(�ð����⵵ �߽�)
class Q1517{
	//Diamond 5
	//�����Ʈ
	//https://www.acmicpc.net/problem/1517
	//�׳� Ǯ�� O(N^2)
	//mergesort�� ����� O(NlogN)���� Ǯ��� �ð� �ʰ� �ȰŸ�
	int N;
	long long ans = 0;
	std::vector<int> v;


private:
	void mergeSort(int start, int end);
	void merge(int start, int mid, int end, int left, int right);
public:
	void run();
};