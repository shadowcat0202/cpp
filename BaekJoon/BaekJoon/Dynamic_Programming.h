#pragma once
#include <iostream>

//완료
class Q1003 {
//https://www.acmicpc.net/problem/1003
	long long dp[41] = {0,};
public:
	void run();
	int fibonacci(int n);

};

class Q11057 {
//https://www.acmicpc.net/problem/11057
	int MOD = 10007;
	long long** dp;
public:
	void run();
	void uphill(int n);
};

class Q2839 {
//https://www.acmicpc.net/problem/2839

	int small = 3;
	int big = 5;

public:
	void run();
	int bag(int n);
};

class Q1463 {
//https://www.acmicpc.net/problem/1463
	int* dp;
public:
	void run();
	void make_dp(int n);
};

class Q11726 {
//https://www.acmicpc.net/problem/11726
	int N;
	int* dp;
public:
	void run();
	void make_dp();
};

class Q1149 {
//https://www.acmicpc.net/problem/11726
	int N;
	int** dp;
public:
	void run();
	void make_dp();
};

class Q14852 {
//https://www.acmicpc.net/problem/14852
	const int MOD = 1e9 + 7;
	int N;
	int* dp_f;
	int* dp_g;
public:
	void run();
	void make_dp();
};

class Q2579 {
	//https://www.acmicpc.net/problem/2579
	int N;
	int* stairs;
	int* dp;

public:
	void run();
	void make_dp();
};

class Q11053 {
	int N;
	int* sequence;
	int* dp;

public:
	void run();
	int make_dp();
};

class Q1912 {
	//https://www.acmicpc.net/problem/1912


	/*
	n개의 정수로 이루어진 임의의 수열이 주어진다.우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.단, 수는 한 개 이상 선택해야 한다.
	예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.여기서 정답은 12 + 21인 33이 정답이 된다.
	
	입력
	첫째 줄에 정수 n(1 ≤ n ≤ 100, 000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다.수는 - 1, 000보다 크거나 같고, 1, 000보다 작거나 같은 정수이다.

	출력
	첫째 줄에 답을 출력한다.
	
	예제 입력 1
	10
	10 -4 3 1 5 6 -35 12 21 -1
	예제 출력 1
	33
	예제 입력 2
	10
	2 1 -4 3 4 -4 6 5 -5 1
	예제 출력 2
	14
	예제 입력 3
	5
	-1 -2 -3 -4 -5
	예제 출력 3
	-1
	*/
	int N;
	int* arr;
	int* dp;

public:
	void run();
	int solution();
};

class Q2156 {
	//https://www.acmicpc.net/problem/2156

	/*
	문제

	효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

	포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
	연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
	
	효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 
	예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.


	입력
	첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.

	출력
	첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.
	예제 입력 1 
	6
	6
	10
	13
	9
	8
	1
	
	예제 출력 1 
	33
	*/
	int N;
	int* arr;
	int* dp;

public:
	void run();
	int solution();
};

//미완료
class Q10844 {
	//https://www.acmicpc.net/problem/10844

	/*
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

예제 입력 1 
1
예제 출력 1 
9

예제 입력 2 
2
예제 출력 2 
17
	*/
	int N;
	int MOD = 1e9;
	int* dp;

public:
	void run();
	int solution();
};