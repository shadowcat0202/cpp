#include "Graph_theory.h"
#include <algorithm>

void Q1197::run() {
	std::cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int v, u, w;
		std::cin >> v >> u >> w;
		edge.push_back({ v,u,w });
	}

	//��� �������� �����͸� �Է� �޾����� MST(�ּҽ���Ʈ��)�� ����� ���� ���۾����� ������ �ϰ� �����Ѵ�
	std::sort(edge.begin(), edge.end());	//Edge�� ���ǵ� compare�� ���� ��������
	
	//������ ���ظ� ���� [0]�迭�� �����ϰ� [1]���� �����Ѵ�
	int* parent = new int[V + 1];
	int* setSize = new int[V + 1];

	//�ʱ�ȭ
	for (int i = 0; i <= V; i++) {
		parent[i] = i;
		setSize[i] = i;
	}


	long long result = 0;
	for (int i = 0; i < edge.size(); i++) {
		//������ �θ� ������ �ʴ� ���, �� ����Ŭ�� �߻����� �������� ����
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
	v1 = getParent(parent, v1);	//v1 ����� �θ� ã��
	v2 = getParent(parent, v2);	//v2 ����� �θ� ã��
	if (v1 == v2)	return true;	//v1���� v2����� �θ� ������ true��ȯ
	else			return false;
}

void Q1197::Union(int* parent, int v1, int v2){
	v1 = getParent(parent, v1);	//v1 ����� �θ� ã��
	v2 = getParent(parent, v2);	//v2 ����� �θ� ã��
	//�θ��� ���ڰ� �� ���� ������ ����
	if (v1 < v2)	parent[v2] = v1;
	else			parent[v1] = v2;
}
