/*
	Kruskal's algorithm
	time: O(E*logE + E*logV)
*/

#include<bits/stdc++.h>
using namespace std;

class Edge  
{  
    public: 
    int src, dest, weight;  
}; 


 
class Graph  
{  
public: 
    int V, E;  
    Edge* edge;  
};  
  
// Create a graph with V vertices and E edges  
Graph* createGraph(int V, int E)  
{  
    Graph* graph = new Graph;  
    graph->V = V;  
    graph->E = E;  
  
    graph->edge = new Edge[E];  
  
    return graph;  
}  
  
// A structure to represent a subset for union-find algo.  
class subset  
{  
    public: 
    int parent;  
    int rank;  
};  

int Compare(const void* a,const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    
    return a1->weight > b1->weight;
}

int find(subset subsets[],int i) {
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets,subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[],int x,int y) {
    int xRoot = find(subsets,x);
    int yRoot = find(subsets,y);
    
    if(subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if(subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
        
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    
    int e=0;    //Index for result[]
    int i=0;    //Index for sorted edges.
    
    //step 1: sort all the edges in ascending order of the weights.
    qsort(graph->edge,graph->E,sizeof(graph->edge[0]),Compare);
    
    subset* subsets = new subset[V];
    
    for(int v=0;v<V;v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while(e < V-1 && i < graph->E ) {
        //step 2: Pick the smallest edge.
        Edge next_edge = graph->edge[i++];
        
        int x = find(subsets,next_edge.src);
        int y = find(subsets,next_edge.dest);
        
        if(x != y) {
            result[e++] = next_edge;
            Union(subsets,x,y);
        }
        //else move to next edge.
    }
    
    cout << "Resultant MST using Kruskal's algo: \n";
    
    for(i=0;i<e;i++) {
        cout << result[i].src <<"--"<<result[i].dest<<" = "<<result[i].weight<<"\n";
    }
}

int main()
 {
    int V=4, E = 5;
	Graph* graph = createGraph(V,E);
	
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;  
  
    KruskalMST(graph);  
    
    return 0;
}
