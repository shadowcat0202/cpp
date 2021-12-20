#include "data_structure.h"

void Q1572::upt(int x, int d, vi& st) {
	st[x] += d;
	if (x)	upt(x / 2, d, st);
}

int Q1572::find(int x, int l, int r, int k, vi& st)
{
	if (l == r)	return l;
	if (st[x * 2] < k)	return find(x * 2 + 1, (l + r) / 2 + 1, r, k - st[x * 2], st);	//오른쪽 자식 호출
	return find(x*2, l, (l+r)/2, k, st);	//왼쪽 자식 호출
}
void Q1572::run() {
	std::cin >> N >> K;
	
	long long ans = 0;
	
	vi st, a;
	st.resize((1 << 17) * 2);
	a.resize(N);

	for (int i = 0; i < N; i++) {
		int buf;
		std::cin >> buf;
		a[i] = buf;
		upt((1<<17) + a[i], 1, st);										// 새로운 숫자를 트리 상에서 더해준다
		if (i < K - 1) continue;										// 아직 k개를 못 채우면 건너뛰기
		ans += long long(find(1, 0, (1 << 17) - 1, (K + 1) / 2, st));	// (k+1)/2개째의 리프노드를 찾아서 답에 더해준다
		upt((1 << 17) + a[i - K + 1], -1, st);							// 사용 마친 숫자 트리 상에서 빼준다
	}
	std::cout << ans << "\n";
}