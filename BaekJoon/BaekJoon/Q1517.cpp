#include "sort.h"

void Q1517::merge(int start, int mid, int end, int left, int right)
{
	std::vector<int> tmp;

	while (left <= mid && right <= end) {
		if (v[left] <= v[right]) {
			tmp.push_back(v[left++]);
		}
		else {
			//left�� right�� ������ �ٲ��� �ϴ� ���� �� ���� ������ idx��ŭ ans�� ���ϱ�(=swap�ϴ� ���)
			tmp.push_back(v[right++]);
			ans += ((long long)mid + 1 - (long long)left);
		}
	}
	//�ܿ� �迭 �־��ֱ�
	while (left <= mid) {
		tmp.push_back(v[left++]);
	}
	while (right <= end) {
		tmp.push_back(v[right++]);
	}

	for (int i = start, j = 0; i <= end; i++, j++) {
		v[i] = tmp[j];
	}
}

void Q1517::mergeSort(int start, int end)
{
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;

	if (start == end)	return;	//���� 2���� ���ϱ� ����(���� 1�� ������)

	mergeSort(start, mid);
	mergeSort(mid+1, end);

	merge(start, mid, end, left, right);

}

void Q1517::run() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int buf;
		std::cin >> buf;
		v.push_back(buf);
	}

	mergeSort(0, N - 1);
	std::cout << ans << "\n";
}