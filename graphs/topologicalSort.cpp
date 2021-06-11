#include<bits/stdc++.h>
using namespace std;
#define l(i,n) for(int i=0;i<n;i++)
typedef long long ll;

/* 
 Topological sort:
 Notes: 
 	1. we must use only DAG(Directed acyclic graph).
 	for all other graphs topologicalSort is not possible!
 * */


class Graph {
public:
	int V;
	list<int> *adj;
	Graph(int V);
	void addEdge(int src, int dest);
	void topologicalSort();
	void topologicalSortUtil(int root, bool visited[], stack<int> &store);
	void printGraph();
	~Graph() {
		printf("\nmemory freed!\n");
	}
};

Graph::Graph(int v) {
	this->V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
	adj[src].push_back(dest);
}

void Graph::printGraph() {
	for (int i = 0; i < V; i++) {
		printf("vertex: %d ->", i);
		for (int x : adj[i]) {
			printf("%d -> ", x);
		}
		printf("\n");
	}
}

void Graph::topologicalSortUtil(int root, bool visited[], stack<int> &store) {
	visited[root] = true;

	for (int node : adj[root]) {
		if (!visited[node])
			topologicalSortUtil(node, visited, store);
	}
	store.push(root);
}

void Graph::topologicalSort() {
	stack<int> store;
	bool visited[V];

	l(i, V) {
		visited[i] = false;
	}

	l(i, V) {
		if (!visited[i])
			topologicalSortUtil(i, visited, store);
	}

	printf("topologicalSort: ");
	while (!store.empty()) {
		printf("%d ", store.top());
		store.pop();
	}
	printf("\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V = 6;
	Graph *g = new Graph(V);

	g->addEdge(5, 2);
	g->addEdge(5, 0);
	g->addEdge(4, 0);
	g->addEdge(4, 1);
	g->addEdge(2, 3);
	g->addEdge(3, 1);

	g->printGraph();

	g->topologicalSort();
	return 0;
}
