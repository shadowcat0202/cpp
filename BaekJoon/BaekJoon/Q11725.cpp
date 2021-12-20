#include "Graph_theory.h"
//DFS
void Q11725::run() {
	int N;
	std::cin >> N;	

	int* parent = new int[N+1];
	std::vector<int>* v = new std::vector<int>[N+1];

	for (int i = 1; i < N; i++) {
		int node1, node2;
		std::cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	bool* visited = new bool[N + 1]	{false,};

	findParent_DFS(v, visited, parent, 1);

	for (int i = 2; i <= N; i++) {
		std::cout << parent[i] << "\n";
	}

	delete[] v, visited, parent;
	v = NULL;
	visited = NULL;
	parent = NULL;
}
void Q11725::findParent_DFS(std::vector<int>* v,  bool* visited, int* parent, int x) {
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!visited[next]) {
			parent[next] = x;
			findParent_DFS(v, visited, parent, next);
		}
	}
}

