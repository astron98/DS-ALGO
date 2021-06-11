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
   
   public static class Pair {
       int v;
       String psf;
       int level;
       
       Pair(int v, String psf, int level) {
           this.v = v;
           this.psf = psf;
           this.level = level;
       }
   }
    
    public static boolean isBipartite(int src, ArrayList<Edge>[] graph, int[] visited) {
        ArrayDeque<Pair> q = new ArrayDeque<>();
        q.add(new Pair(src, src+"",0));
        
        while(q.size()>0) {
            Pair top = q.removeFirst();
            
            if(visited[top.v]==-1){
                visited[top.v] = top.level;
            }
            else {
                if(top.level!=visited[top.v]) {
                    //odd cycle detected
                    return false;
                }
            }                
            for(Edge e : graph[top.v]) {
                if(visited[e.nbr]==-1) {
                    q.add(new Pair(e.nbr, top.psf+e.nbr, top.level+1));
                    
                }
            }
        }
        
        return true;
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
        boolean res = true;
        int[] visited = new int[vtces];
        Arrays.fill(visited, -1);
        for(int i=0;i<vtces; i++) {
            if(visited[i] ==-1){
                if(!isBipartite(i, graph, visited)) {
                    res = false;
                    break;
                }
            }
        }
        
        System.out.println(res);
   }
}