
#include <bits/stdc++.h> 
using namespace std; 

class Graph {
	int V;
	list<int> *adj;
	
public:
	Graph(int x) {
		this->V = x;
		adj = new list<int>[V];
	}
	
	//DFS for a given source s.
	void DFS(int s);
	void addEdge(int source,int dest);
	~Graph() {
		cout<<"\nThe allocated memory to the obj is freed here...";
	}
};

void Graph::addEdge(int source,int dest) {
	adj[source].push_back(dest);
}

void Graph::DFS(int s) {
	bool visited[V] = {false};
	
	stack<int> st;
	st.push(s);
	visited[s] = true;
	
	while(!st.empty()) {
		int temp = st.top();
		cout<< temp <<" ";
		st.pop();
		visited[temp] = true;
		
		for(auto x: adj[temp]) {
			if(!visited[x]) {
				visited[x] = true;
				st.push(x);
			}
		}
		
	}
	
}

int main() {
	
	Graph g(5);
	g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
    
    g.DFS(0);
    
	return 0;
}
