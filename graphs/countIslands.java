import java.io.*;
import java.util.*;

public class countIslands {
    
    public static void countIslands(int i, int j, int[][] arr, boolean[][] visited) {
        int n = arr.length, m=arr[0].length;
        if(i>=n || j>=m || i<0 || j<0) {
            return;
        }    

        if(arr[i][j]==1 || visited[i][j])
            return;
        
        visited[i][j] = true;
        countIslands(i-1, j, arr, visited);
        countIslands(i, j+1, arr, visited);
        countIslands(i+1, j, arr, visited);
        countIslands(i, j-1, arr, visited);
    }
    
    public static void countUtil(int[][] arr) {
        int n = arr.length, m=arr[0].length, count=0;
        boolean[][] visited = new boolean[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && arr[i][j]==0){
                  countIslands(i, j, arr, visited);
                  count++;    
                }
            }
        }
        System.out.println(count);
    }
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new FileReader("../input.txt"));

      int m = Integer.parseInt(br.readLine());
      int n = Integer.parseInt(br.readLine());
      int[][] arr = new int[m][n];

      for (int i = 0; i < arr.length; i++) {
         String parts = br.readLine();
         for (int j = 0; j < arr[0].length; j++) {
            arr[i][j] = Integer.parseInt(parts.split(" ")[j]);
         }
      }

      // write your code here
      
      countUtil(arr);
   }
}