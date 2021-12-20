#include "Graph_theory.h"
#include <algorithm>

void Q1197::run() {
	std::cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int v, u, w;
		std::cin >> v >> u >> w;
		edge.push_back({ v,u,w });
	}

	//모든 간선들의 데이터를 입력 받았으면 MST(최소신장트리)를 만들기 위한 밑작업으로 정렬을 하고 시작한다
	std::sort(edge.begin(), edge.end());	//Edge에 정의된 compare에 의해 오름차순
	
	//직관적 이해를 위해 [0]배열은 무시하고 [1]부터 시작한다
	int* parent = new int[V + 1];
	int* setSize = new int[V + 1];

	//초기화
	for (int i = 0; i <= V; i++) {
		parent[i] = i;
		setSize[i] = i;
	}


	long long result = 0;
	for (int i = 0; i < edge.size(); i++) {
		//동일한 부모를 가지지 않는 경우, 즉 사이클이 발생하지 않을때만 선택
		if (!sameParent(parent, edge[i].v1, edge[i].v2)) {
			result += edge[i].w;
			Union(parent, edge[i].v1, edge[i].v2);
			
		}
	}

	std::cout << result << "\n";
}
int Q1197::getParent(int* parent, int v) {
	if (parent[v] == v)	return v;
	return parent[v] = getParent(parent, parent[v]);
}

bool Q1197::sameParent(int* parent, int v1, int v2){
	v1 = getParent(parent, v1);	//v1 노드의 부모 찾기
	v2 = getParent(parent, v2);	//v2 노드의 부모 찾기
	if (v1 == v2)	return true;	//v1노드와 v2노드의 부모가 같으면 true반환
	else			return false;
}

void Q1197::Union(int* parent, int v1, int v2){
	v1 = getParent(parent, v1);	//v1 노드의 부모 찾기
	v2 = getParent(parent, v2);	//v2 노드의 부모 찾기
	//부모의 숫자가 더 작은 쪽으로 병합
	if (v1 < v2)	parent[v2] = v1;
	else			parent[v1] = v2;
}
