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
		//w_graph = from���� to ������ �̵��ϴµ� �ʿ��� ����ġ
	}

	//�ʱ�ȭ
	dist = new int[V + 1];
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[start_node] = 0;	//���������� �ִ� �̵� ��δ� 0

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
	pq.push({ start_node, 0});	//������������ �������� ������ ��� 0���� ����

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.w > dist[now.to])	continue;	//���۳�忡�� now�� �������� �ִܰŸ��� ũ��� 

		for (int i = 0; i < w_graph[now.to].size(); i++) {
			Node next = w_graph[now.to][i];
			//(���������������� ����������� �ִܰŸ� + ���� �������� �Ÿ�) < (���ŵǾ��� ���۳��κ��� ���� �������� �Ÿ�) ��

			if (next.w + now.w < dist[next.to]) {	
				dist[next.to] = next.w + now.w;		//dist�� ���۳�忡�� �ش� �������� �ִܰŸ� ����
				pq.push({ dist[next.to], next.to });	//���� �������� �ִܰŸ�, ������� ť�� ����
			}
		}
	}
}
