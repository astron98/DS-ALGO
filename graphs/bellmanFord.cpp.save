#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int>

void addEdge(vector<PI> adj[],int src,int dest,int weight) {
    adj[src].push_back(make_pair(dest,weight));
    adj[dest].push_back(make_pair(src,weight));
}

void shortestPath(vector<PI> adj[],int V,int src) {
    priority_queue<PI, vector<PI>, greater<PI>> q;

    vector<int> dist(V,INT_MAX);
    dist[src] = 0;

    q.push(make_pair(0,src));

    while(!q.empty()) {
        int u = q.top().second;

        q.pop();

        for(PI x: adj[u]) {
            int v = x.first;
            int weight = x.second;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                q.push(make_pair(dist[v],v));
            }
        }
    }

    //print the negative weights if there any of such.
    printf("Vertex Distance from source\n");
    for(int i=0;i<V;i++)
        printf("%d \t %d",i,dist[i]);
}

int main() {
    int V = 9;
    vector<PI> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);

    return 0;
}
