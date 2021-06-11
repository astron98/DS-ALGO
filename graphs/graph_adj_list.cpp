#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int start,int end) {
    //int n = adj->size();
    //printf("n value:%d\n",n);
    adj[start].push_back(end);
    adj[end].push_back(start);
}

void printGraph(vector<int> adj[],int V) {
    for(int i=0;i<V;i++){
	cout<<"head:"<<i<<"\n";
	for(auto j:adj[i]) {
	    cout<<"->"<< j;
	}
	printf("\n");
    }
}

int main(){
    
    int V = 5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj,V);
    return 0;
}
