#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
class Q3190{
	//https://www.acmicpc.net/problem/3190

	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };

	int N, K, L;
	int play_time = 0;
	int** apple_map;
	std::queue<std::pair<int, char>> move_q;
	std::deque<std::pair<int,int>> snake;

	int dir;


public:
	void run();
	void input();
	bool move();
	void del();
};

//�ذ�(�ð��� ���ϼ� �ִ� ����� ������?)
class Q1158 {	
	//Silver 5
	//�似Ǫ�� ����
	//https://www.acmicpc.net/problem/1158

	int N, K;
	std::deque<int> dq;
	std::queue<int> q;
private:

public:
	void run();
};

//�ذ�
class Q1168{
	//Silver 3
	//�似Ǫ�� ���� 2(���׸�Ʈ Ʈ��?)
	//https://www.acmicpc.net/problem/1168
private:
	int makeTree(std::vector<int>& tree, int node, int start, int end);
	int update(std::vector<int>& tree, int node, int start, int end, int del);
	int query(std::vector<int>& tree, int node, int start, int end, int order);
public:
	void run();
};

//�ذ�
class Q1043 {	
	//Gold 4
	//https://www.acmicpc.net/problem/1043
	//�и�����

	int Person_max, Party_max;
	int parents[51];
	std::vector<int> Know;
	std::vector<std::vector<int> > party;

private:
	void input();
	int Find(int p);
	void Union(int p1, int p2);
public:
	void run();
};

//�ذ�(map)
class Q1351 {
	//Gold 4
	//���� ����(�̰� �� �ڷᱸ�� ����?)
	//https://www.acmicpc.net/problem/1351
	/*
	A_0 = 1
	A_i = A_[i/P] + A_[i/Q]   (i >= 1)
	
	0<= N <= 10^12
	2 <= P, Q <= 10^9

	A_N = ?
	*/
	int N, P, Q;
private:
	long long memo(std::map<long long, long long>& dp, long long i);
public:
	void run();
};

//(���׸�Ʈ, ����Ʈ��)
class Q1572 {
	//Diadond 5
	//�߾Ӱ�
	//https://www.acmicpc.net/problem/1572

	typedef std::vector<int> vi;
	int N, K;
private:
	void upt(int x, int d, vi& st);
	int find(int x, int l, int r, int k, vi& st);
public:
	void run();

};

//�ذ�
class Q1717 {
	//Gold 4
	//������ ǥ��
	//https://www.acmicpc.net/problem/1717

	int N;	//(1<= N <= 10^6)
	int M;	//(1<= N <= 10^5)
	std::vector<int> arr;
private:
	int Find(int a);
	void Union(int a, int b);
public:
	void run();
};

class Q1395 {
	//Diamond 3
	//���׸�ƮƮ��(������?)
	//https://www.acmicpc.net/problem/1395
	int tree_height;
	int N, M;
	std::vector<int> tree;
	std::vector<int> lazy;

private:
	void updateLazy(int left, int right, int node);
	void updateRange(int left, int right, int range_left, int range_right, int node);
	int sumOnSwitch(int left, int right, int range_left, int range_right, int node);
	void show_tree();
public:
	void run();
};

//�ذ�
class Q1725 {
	//Diamond 5
	//���׸�ƮƮ��, ��������, ����
	//https://www.acmicpc.net/problem/1725	(����)
	//https://www.acmicpc.net/problem/6549	(���׸�ƮƮ�� + ��������)
	const long long INF = 2000000000;
	int N;
	long long ans = 0;
	std::vector<long long> h, seg;
	std::stack<int> s;
private:
	int init(int node, int start, int end);
	int query(int node, int start, int end, int l, int r);
	void segment_solve(int left, int right);
	void use_segmentTree();
	void use_stack();
public:
	void run();
};

//�ذ�(�켱���� ���� ������ �׳� priority_queue�� ���� ����غ���
class Q1781 {
	//Gold 2
	//https://www.acmicpc.net/problem/1781
	
	//ó�� �����ߴ���
	/*
	struct data {
		int dead_line;
		int cup;
	};
	*/
	
	int N;
	std::vector<std::pair<int,int>> v;
	std::priority_queue<int> pq;


private:
	
public:
	void run();

};