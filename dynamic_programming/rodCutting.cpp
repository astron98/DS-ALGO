/*
//java sol. for Rod cutting problem.

import java.io.*;
import java.util.*;

public class Main {
    public static int solver(int n, int l, int t[][], int prices[]) {
        if(n==0 || l==0)
            return 0;
        if(t[n][l] != -1) return t[n][l];
        
        if(n <= l) {
            t[n][l] = Math.max(prices[n-1] + solver(n, l - n, t, prices),
                                solver(n-1, l, t, prices));
        }
        else
            t[n][l] = solver(n-1, l, t, prices);
    
        return t[n][l];
    }    

  // space: N^2, time:N^2
  public static int solution(int[] prices) {
    // write your code here
    int l = prices.length;
    int t[][] = new int[l+1][l+1];
    
    for(int row[]:t)
        Arrays.fill(row,-1);
        
    solver(prices.length, l, t, prices);
    return t[l][l];
  }

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] prices = new int[n];
    for (int i = 0; i < n; i++) {
      prices[i] = scn.nextInt();
    }
    System.out.println(solution(prices));
  }

}

*/
// method 2: tabulation (most optimal sol.)
/*
    public static int solution(int[] prices){
        int[] dp = new int[prices.length + 1];
        for(int i = 1; i < dp.length; i++){
            int max = Integer.MIN_VALUE;
            for(int j = 0; j < i; j++){
                max = Math.max(max, dp[i - j - 1] + prices[j]);
            }
            dp[i] = max;
        }
        return dp[dp.length - 1];
    }


   // space: N, time:N^2
*/


/*
testcases:

case 1:
input:
N
arr[0]...arr[N-1]
8
1   
5   
8   
9  
10 
17  
17  
20

output:
22
------------------
*/