#include "data_structure.h"
#include "myDisplay.h"
#include <cmath>

void Q1395::show_tree()
{
	std::vector<int> newline = { 0,2,6 };
	std::cout << "segment_tree\n";	
	printf("[%d] %d [%d] %d [%d] %d [%d]\n", tree[3], tree[1], tree[4], tree[0], tree[5], tree[2], tree[6]);

	std::cout << "lazy_tree\n";
	printf("[%d] %d [%d] %d [%d] %d [%d]\n", lazy[3], lazy[1], lazy[4], lazy[0], lazy[5], lazy[2], lazy[6]);
	Wait();
}


void Q1395::updateLazy(int left, int right, int node)
{
	if (lazy[node] % 2 == 1) {
		tree[node] = (right - left + 1) - tree[node];
		if (left != right) {	//리프 노드가 아닌경우
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];			
		}
		lazy[node] = 0;
	}
	
}

void Q1395::updateRange(int left, int right, int range_left, int range_right, int node)
{
	updateLazy(left, right, node);
	if (range_right < left || right < range_left) {
		return;
	}

	if (range_left <= left && right <= range_right) {
		tree[node] = (right - left + 1) - tree[node];
		if (left != right) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return;
	}
	int mid = (left + right) / 2;
	updateRange(left, mid, range_left, range_right, node * 2);
	updateRange(mid+1, right, range_left, range_right, node * 2 + 1);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;

}

int Q1395::sumOnSwitch(int left, int right, int range_left, int range_right, int node)
{
	updateLazy(left, right, node);
	if (range_right < left || right < range_left)	return 0;
	if (range_left <= left && right <= range_right)	return tree[node];

	int mid = (left + right) / 2;
	return sumOnSwitch(left, mid, range_left, range_right, node * 2) + sumOnSwitch(mid + 1, right, range_left, range_right, node * 2 + 1);
}



void Q1395::run() {
	std::cin >> N >> M;

	tree_height = (int)ceil(log2(N));
	tree = std::vector<int>(1 << (tree_height + 1));
	lazy = std::vector<int>(1 << (tree_height + 1));


	for (int i = 0; i < M; i++) {
		bool state = false;
		int chnage_A_idx, change_B_idx;
		std::cin >> state >> chnage_A_idx >> change_B_idx;

		if (state == true) {
			std::cout << sumOnSwitch(1, N, chnage_A_idx, change_B_idx, 1) << "\n";
		}
		else {
			updateRange(1, N, chnage_A_idx, change_B_idx, 1);
		}
	}
}