#include "Graph_theory.h"
#define INF 1e9

void Q1753::run() {
	std::cin >> V >> E;
	int start_node;
	std::cin >> start_node;

	w_graph = new std::vector<Node>[V+1];

	for (int i = 0; i < E; i++) {
		int from, to, w;
		std::cin >> from >> to >> w;
		w_graph[from].push_back(Node{ to, w });
		//w_graph = from에서 to 노드까지 이동하는데 필요한 가중치
	}

	//초기화
	dist = new int[V + 1];
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[start_node] = 0;	//시작지점의 최단 이동 경로는 0

	dijkstra(start_node);

	

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF)	std::cout << dist[i] << "\n";
		else	std::cout << "INF\n";
	}

	delete[] w_graph, dist;
	w_graph = NULL;
	dist = NULL;

}

void Q1753::dijkstra(int start_node) {
	std::priority_queue<Node> pq;	//
	pq.push({ start_node, 0});	//시작지점에서 시작지점 까지의 비용 0으로 시작

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.w > dist[now.to])	continue;	//시작노드에서 now의 노드까지의 최단거리의 크기와 

		for (int i = 0; i < w_graph[now.to].size(); i++) {
			Node next = w_graph[now.to][i];
			//(시작지점에서부터 현재노드까지의 최단거리 + 다음 노드까지의 거리) < (갱신되었던 시작노드로부터 다음 노드까지의 거리) 비교

			if (next.w + now.w < dist[next.to]) {	
				dist[next.to] = next.w + now.w;		//dist에 시작노드에서 해당 노드까지의 최단거리 갱신
				pq.push({ dist[next.to], next.to });	//다음 노드까지의 최단거리, 다음노드 큐에 삽입
			}
		}
	}
}
