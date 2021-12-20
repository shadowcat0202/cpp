#include "Graph_theory.h";
#include <time.h>

void Q2644::run() {
	int N = 0;	//명수
	int a, b;	//a와 b의 촌수
	int line = 0;	//연결 관계 줄 수
	std::cin >> N;
	std::cin >> a >> b;

	int* dist = new int[N + 1]{0,};	//각 번호당 촌수
	std::vector<int>* v = new std::vector<int>[N + 1];
	bool* visited = new bool[N + 1]{ false, };

	
	
	std::cin >> line;

	for (int i = 0; i < line; i++) {
		int child, parents;
		std::cin >> parents >> child;
		v[parents].push_back(child);
		v[child].push_back(parents);
	}

	int count = -1;
	int* result = &count;

	family_tree_DFS(v, visited, a, b, 0, result);

	std::cout << *result << "\n";
	std::cout << family_tree_BFS(v, dist, a, b) << "\n";
	
	delete[] v, visited, dist;
	v = NULL;
	visited = NULL;
	result = NULL;
	dist = NULL;

}

void Q2644::family_tree_DFS(std::vector<int>* v, bool* visited, int p, int c, int cnt, int* result) {
	for (int i = 0; i < v[p].size(); i++) {
		visited[p] = true;
		if (p == c) {
			*result = cnt;
			return;
		}
		int next = v[p][i];
		if (!visited[next]) {
			family_tree_DFS(v, visited, next, c, cnt+1, result);
		}
	}
	return;
}

int Q2644::family_tree_BFS(std::vector<int>* v, int* dist, int start, int end){
	std::queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == end)	return dist[end];

		long size = v[now].size();

		for (int i = 0; i < size; i++) {
			int next = v[now][i];
			if (!dist[next]) {
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
	return -1;
}
