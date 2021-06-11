#include<bits/stdc++.h>
using namespace std;

#define V 9

void dijkstra(int graph[V][V],int source);


//Find the vertex with the minimum distance in the sptSet.
int findMinDistVertex(bool sptSet[],int dist[]) {
	int minIndex,min=INT_MAX;
	for(int i=0;i<V;i++) {
		if(sptSet[i]==false && dist[i]<min) {
			min = dist[i];
			minIndex = i;
		}
	}
	//printf("current min:%d",minIndex);
	return minIndex;
}

void printResult(int dist[]) {
	printf("\n");
	for(int i=0;i<V;i++)
		printf("\nvertex %d: minDistance:%d",i,dist[i]);
}

void dijkstra(int graph[V][V],int source) {
	bool sptSet[V];
	int dist[V];
	
	for (int i = 0; i < V; i++) 
	    dist[i] = INT_MAX, sptSet[i] = false; 
	
	dist[source] = 0;
	
	for(int i=0;i<V-1;i++) {
		int u = findMinDistVertex(sptSet,dist);
		sptSet[u] = true;
		
		//update distances of all the adjacent vertices.
		for(int j=0;j < V;j++) {
			if(!sptSet[j] && graph[u][j]  && dist[u]+graph[u][j] < dist[j]) {
				dist[j] = dist[u]+graph[u][j];
			}
		}	
	}
	
	printResult(dist);
	
}

int main()
{
	/* creating a graph */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijkstra(graph,0);                    
	
	return 0;
}
