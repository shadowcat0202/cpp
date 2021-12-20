#include "data_structure.h"

int Q1717::Find(int a)
{
	if (arr[a] == a)	return a;
	return arr[a] = Find(arr[a]);
}

void Q1717::Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a != b)	arr[a] = b;
}

void Q1717::run() {
	std::cin >> N >> M;

	arr.resize(N+1);
	for (int i = 0; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < M; i++) {
		bool oper;
		int a, b;
		std::cin >> oper >> a >> b;

		if (oper) {	//같은 집합인지 확인 출력 (YES/NO)
			if (Find(a) == Find(b)) {
				std::cout << "YES\n";
			}
			else {
				std::cout << "NO\n";
			}
		}
		else {	//합집합
			Union(a, b);
		}
	}
}