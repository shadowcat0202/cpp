#include "data_structure.h"

int Q1725::init(int node, int start, int end)
{
	if (start == end)	return seg[node] = start;
	int mid = (start + end) / 2;
	int left_idx = init(2 * node, start, mid);
	int right_idx = init(2 * node + 1, mid + 1, end);

	return seg[node] = h[left_idx] < h[right_idx] ? left_idx : right_idx;
}

int Q1725::query(int node, int start, int end, int l, int r)
{
	if (end < l || r < start)	return INF;			//찾는 구간이 겹치치 않을때
	if (l <= start && end <= r)	return seg[node];	//찾는 구간이 완전히 겹칠때

	//찾는구간이 부분적으로 겹칠때
	int mid = (start + end) / 2;
	int left_idx = query(2 * node, start, mid, l, r);
	int right_idx = query(2 * node + 1, mid + 1, end, l, r);

	if (left_idx == INF)	return right_idx;
	else if (right_idx == INF)	return left_idx;
	else return	h[left_idx] < h[right_idx] ? left_idx : right_idx;
}

void Q1725::segment_solve(int left, int right)
{
	if (left > right)	return;
	int idx = query(1, 0, N - 1, left, right);	//구간내 최소값 찾기

	ans = std::max((long long)ans, h[idx] * (right - left + 1));
	segment_solve(left, idx - 1);
	segment_solve(idx + 1, right);
}

void Q1725::use_segmentTree()
{
	while (true) {
		ans = 0;
		std::cin >> N;
		if (N == 0)	break;
		h = std::vector<long long>(N + 3, 0);
		seg = std::vector<long long>(N * 4, 0);

		for (int i = 0; i < N; i++) {
			std::cin >> h[i];
		}

		init(1, 0, N - 1);	//세그먼트 트리 제작
		segment_solve(0, N - 1);

		std::cout << ans << "\n";
	}
	
}

void Q1725::use_stack()
{
	std::cin >> N;
	h = std::vector<long long>(N + 2, 0);

	for (int i = 1; i <= N; i++) {
		std::cin >> h[i];
	}
	s.push(0);
	for (int i = 1; i <= N+1; i++) {
		while (!s.empty() && h[s.top()] > h[i]) {
			int check = s.top();
			s.pop();
			ans = std::max((long long)ans, h[check] * (i - s.top() - 1));
		}
		s.push(i);
	}

	std::cout << ans << "\n";
}

void Q1725::run() {
	//use_vetor();
	use_segmentTree();
}