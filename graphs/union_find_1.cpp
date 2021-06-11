/*
 * Union-find algorithm part 1:
 * time complexity: O(n)
 * 
 * Uses: Kruskal's algorithm
 * */

#include <bits/stdc++.h> 
using namespace std; 

class Edge {
public:
	int src,dest;
};

class Graph {
public:
	int V,E;
	Edge *edge;
	
	//Graph(int V,int E) {
		//this->V = V;
		//this->E = E;
		//edge = new Edge[E * sizeof(Edge)];
	//}
};

int find(int parent[],int i) {
	if(parent[i] == -1)
		return i;
	return find(parent,parent[i]);
}

void Union(int parent[],int x,int y) {
	int xset = find(parent,x);
	int yset = find(parent,y);
	
	if(xset != yset) 
		parent[xset] = yset;
}

int isCyclic(Graph *graph) {
	//int *parent = new int[graph->V * sizeof(int)];
	int parent[graph->V];
	memset(parent,-1,graph->V * sizeof(int));
	
	for(int i=0;i<graph->E;i++) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
		
		if(x==y)
			return 1;
		
		Union(parent,x,y);
	}
	return 0;
}

Graph* createGraph(int V,int E) {
	Graph* graph = new Graph();
	
	graph->V = V;
	graph->E = E;
	
	graph->edge = new Edge[graph->E];
	
	return graph;
} 

int main() {

	//Vertices and Edges for the graph
	//Note: remember to change these two parameter when giving a new graph.
	int V = 4,E = 3;
	Graph* graph = createGraph(V,E);
	
	//add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
							
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	
	graph->edge[2].src = 2;
	graph->edge[2].dest = 3;
	
	if(isCyclic(graph)) 
		cout<< "graph contains cycle!";
	else
		cout << "graph doesn't contains cycle!";
							
							
	return 0;
}
