import java.io.*;
import java.util.*;

//dikjstra's algorithm: to find the shortest path from a node to all the other nodes in the graph.

public class Main {
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }
   
   public static class Pair implements Comparable<Pair>{
       int val;
       String psf;
       int weight;
       
       Pair(int val, String psf, int weight) {
           this.val = val;
           this.psf = psf;
           this.weight = weight;
       }
       
       public int compareTo(Pair p) {
           return this.weight - p.weight;
       }
   }
   
   public static void dijkstra(int src, ArrayList<Edge>[] graph) {
       boolean[] visited = new boolean[graph.length];
       Arrays.fill(visited, false);
       PriorityQueue<Pair> pq = new PriorityQueue<>();
       pq.add(new Pair(src, ""+src, 0));
       
       while(pq.size()>0) {
            Pair top = pq.remove();
            if(!visited[top.val]) {
                visited[top.val] = true;
                System.out.println(top.val + " via " + top.psf + " @ " + top.weight);
            }
            
            for(Edge e:graph[top.val]) {
                if(!visited[e.nbr]) {
                    pq.add(new Pair(e.nbr, top.psf+e.nbr, top.weight+e.wt));
                }
            }
       }
       
   }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt));
         graph[v2].add(new Edge(v2, v1, wt));
      }

      int src = Integer.parseInt(br.readLine());
      // write your code here
      dijkstra(src, graph);
      
   }
}