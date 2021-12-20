#include "data_structure.h";
#include <cmath>

int Q1168::makeTree(std::vector<int>& tree, int node, int start, int end)
{
	if (start == end)	return tree[node] = 1;	//리프 노드는 모두 1로 설정
	int mid = (start + end) / 2;
	return tree[node] = makeTree(tree, node * 2, start, mid) 
		+ makeTree(tree, node * 2 + 1, mid + 1, end);
}

int Q1168::update(std::vector<int>& tree, int node, int start, int end, int del)
{
	tree[node]--;
	if (start == end) return 0;
	else {
		int mid = (start + end) / 2;	//변경해야할 노드가 현재 노드에서 어느쪽 가지에 있는지 판단
		if (del <= mid)	return update(tree, 2 * node, start, mid, del);
		else return update(tree, 2 * node + 1, mid + 1, end, del);
	}
	return 0;
}

int Q1168::query(std::vector<int>& tree, int node, int start, int end, int order)
{
	if (start == end)	return start;
	int mid = (start + end) / 2;
	if (order <= tree[node * 2])	return query(tree, 2 * node, start, mid, order);
	else	return query(tree, 2 * node + 1, mid + 1, end, order - tree[node * 2]);
}

void Q1168::run() {
	int N, K;
	std::cin >> N >> K;

	std::vector<int> segmentTree;
	segmentTree.resize(1 << (int)(ceil(log2(N)) + 1));

	makeTree(segmentTree, 1, 1, N);

	int idx = 1;
	std::cout << "<";

	for(int i = 0; i < N;i++){
		int size = N - i;
		idx += K - 1;

		if (idx % size == 0)	idx = size;
		else if (idx > size)	idx %= size;

		int num = query(segmentTree, 1, 1, N, idx);
		update(segmentTree, 1, 1, N, num);
		std::cout << num << (i == N - 1 ? ">" : ",");
	}

	
}