/*
 * Finding all the articulation points using tarjan's algorithm
 * */

#include<bits/stdc++.h>

using namespace std;
#define l(i,n) for(int i=0;i<n;i++)

class Graph {
public:
	int V;
	list<int> *adj;
	void apUtil(int v,bool vis[],int disc[],int low[],int parent[],bool ap[]);

	Graph(int vertex);
	void addEdge(int v,int w);
	void printAP();	
	
	~Graph() {
		printf("\nthe memory has been deallocated...\n");
	}
};

Graph::Graph(int vertex) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int src,int dest) {
		adj[src].push_back(dest);
		adj[dest].push_back(src);
}

void Graph::apUtil(int u,bool vis[],int disc[],int low[],int parent[],bool ap[]) {
	static int time = 0;
	int child =0;
	
	vis[u] = true;
	disc[u] = low[u] = ++time;
	
	list<int>::iterator it;
	
	for(it=adj[u].begin();it!=adj[u].end();it++) {
		int v = *it;
		if(!vis[v]) {
			parent[v] = u;
			child++;
			apUtil(v,vis,disc,low,parent,ap);
			
			low[u] = min(low[u],low[v]);
			
			if(parent[u]!= -1 && low[v] >= disc[u])	//other than root node.
				ap[u] = true;
			
			if(parent[u]==-1 && child>1)	//for the root of the dfs graph.
				ap[u] = true;
				
		}
		else if(v!=parent[u])
			low[u] = min(low[u],disc[v]);
	}
}

void Graph::printAP() {
	bool vis[V],ap[V];
	int low[V],disc[V],parent[V];
	
	l(i,V) {
		parent[i] = -1;
		vis[i] = false;
		ap[i] = false;
	}
	
	l(i,V) {
		if(!vis[i])
			apUtil(i,vis,disc,low,parent,ap);
	}
	
	l(i,V) {
		if(ap[i])
			printf("%d ",i);
	}
	printf("\n");
	
	//delete [] vis,disc,parent,ap;
}

int main()
 {
	//cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.printAP(); 
	
	return 0;
}
