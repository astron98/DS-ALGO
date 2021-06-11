/*
 * union_find_2
 * Using Rank and Path Compression method.
 * Time complexity: O(logV)
 * 					This is due to the path compresssion technique.
 * */

#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int src,dest;
};

struct Graph {
	int V,E;
	struct Edge* edge;
};

struct Subset {
	int rank,parent;
};

struct Graph* createGraph(int V,int E) {
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;
	
	graph->edge = new Edge[E];
	
	return graph;
}

int find(struct Subset subset[],int i) {
	if(subset[i].parent != i)
		subset[i].parent = find(subset,subset[i].parent);	//doing path compression here.
		
	return subset[i].parent;	
}

void Union(struct Subset subset[],int x,int y) {
	int xRoot = find(subset,x);
	int yRoot = find(subset,y);
	
	if(subset[xRoot].rank < subset[yRoot].rank) {
		subset[xRoot].parent = yRoot;
	}
	else if(subset[xRoot].rank > subset[yRoot].rank) {
		subset[yRoot].parent = xRoot;
	}
	else {
		subset[yRoot].parent = xRoot;
		subset[xRoot].rank++;
	}
		
} 

int isCyclic(struct Graph* graph) {
	int V = graph->V,E = graph->E;
	
	struct Subset* subset = new Subset[V];
	
	for(int v=0;v<V;v++) {
		subset[v].parent = v;
		subset[v].rank = 0;
	}
	
	for(int e=0;e<E;++e) {
		int x = find(subset,graph->edge[e].src);
		int y = find(subset,graph->edge[e].dest);
		
		if(x == y)
			return 1;
		
		Union(subset,x,y);	
	}
	return 0;
}

int main()
 {
	int V=4,E=3;
	Graph* graph = createGraph(V,E);
	//add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
							
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	
	graph->edge[2].src = 2;
	graph->edge[2].dest = 3;
	
	if(isCyclic(graph))
		cout << "Has a cycle!!\n";
	else
		cout << "Doesn't have a cycle!\n";
	return 0;
}
