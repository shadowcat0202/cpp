#include "sort.h"

void Q1517::merge(int start, int mid, int end, int left, int right)
{
	std::vector<int> tmp;

	while (left <= mid && right <= end) {
		if (v[left] <= v[right]) {
			tmp.push_back(v[left++]);
		}
		else {
			//left와 right의 순서가 바뀌어야 하는 경우는 두 수가 떨어진 idx만큼 ans에 더하기(=swap하는 경우)
			tmp.push_back(v[right++]);
			ans += ((long long)mid + 1 - (long long)left);
		}
	}
	//잔여 배열 넣어주기
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

	if (start == end)	return;	//원소 2개를 비교하기 위해(원소 1개 방지용)

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