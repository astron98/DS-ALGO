import java.io.*;
import java.util.*;

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

     // check for cycle.
    public static boolean isCyclic(int src, int parent, ArrayList<Edge>[] graph, boolean[] visited) {
        visited[src] = true;
        
        for(Edge e : graph[src]) {
            if(!visited[e.nbr]) { 
                if(isCyclic(e.nbr, src, graph, visited)) {
                   return true; 
                }
            }       
                   
            /* if adjacent vertex is visited n its not parent of src then its a cycle */
            else if(e.nbr != parent)
                return true;
        }
        
        return false;
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

      // write your code here
      boolean[] visited = new boolean[vtces];
      for(int i=0;i<vtces; i++) {
        if(!visited[i]) {    
            if(isCyclic(i, Integer.MIN_VALUE, graph, visited)){
                System.out.println(true);
                return;
            }
        }
      }
      
      System.out.println(false);
   }
}