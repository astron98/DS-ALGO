#include <bits/stdc++.h> 
using namespace std; 

class Graph {
	int V;
	list<int> *adj;
	
public:
	Graph(int x);
		
	void addEdge(int s,int e);
	//print BFS from a given source S.
	void BFS(int s);
	
	//destructor
	~Graph() {
		cout<<"\n The object's memory-space is free now...";
	}
};

Graph::Graph(int x) {
	this->V = x;
	adj = new list<int>[V];
}

void Graph::addEdge(int s,int e) {
	adj[s].push_back(e);
}

void Graph::BFS(int s) {
	bool checked[V] = {false}; 
	
	queue<int> q;
	checked[s] = true;
	
	q.push(s);
	while(!q.empty()) {
		int temp = q.front();
		cout<< temp <<" ";
		q.pop();
		
		for(auto x:adj[temp]) {
			if(!checked[x]){
				q.push(x);
				checked[x] = true;
			}
		}
	}
}

int main() {
	//create a directed graph.
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    cout<<"BFS traversal starting from vertex 2: \n";
    g.BFS(2);
    
    
	return 0;
}
