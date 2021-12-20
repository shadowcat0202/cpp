#include "data_structure.h"

void Q1572::upt(int x, int d, vi& st) {
	st[x] += d;
	if (x)	upt(x / 2, d, st);
}

int Q1572::find(int x, int l, int r, int k, vi& st)
{
	if (l == r)	return l;
	if (st[x * 2] < k)	return find(x * 2 + 1, (l + r) / 2 + 1, r, k - st[x * 2], st);	//������ �ڽ� ȣ��
	return find(x*2, l, (l+r)/2, k, st);	//���� �ڽ� ȣ��
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
		upt((1<<17) + a[i], 1, st);										// ���ο� ���ڸ� Ʈ�� �󿡼� �����ش�
		if (i < K - 1) continue;										// ���� k���� �� ä��� �ǳʶٱ�
		ans += long long(find(1, 0, (1 << 17) - 1, (K + 1) / 2, st));	// (k+1)/2��°�� ������带 ã�Ƽ� �信 �����ش�
		upt((1 << 17) + a[i - K + 1], -1, st);							// ��� ��ģ ���� Ʈ�� �󿡼� ���ش�
	}
	std::cout << ans << "\n";
}