// Dynamic Programming

/*
1.
Ques : LONGEST COMMON SUBSEQUENCE

Time : n^2
Space: n^2
 */

//Code-----------------------------------

int t[1001][1001];

// bottom-up
int lcs(int m, int n, string &x, string &y) {
    if (m == 0 || n == 0)
        return 0;

    if (t[m][n] != -1) return t[m][n];

    if (x[m - 1] == y[n - 1])
        t[m][n] = 1 + lcs(m - 1, n - 1, x, y);
    else
        t[m][n] = max(lcs(m - 1, n, x, y), lcs(m, n - 1, x, y));

    return t[m][n];
}

//top-down
rep(i, m + 1) {
    rep(j, n + 1) {
        if (i == 0 || j == 0)
            t[i][j] = 0;
        else if (x[i - 1] == y[j - 1])
            t[i][j] = 1 + t[i - 1][j - 1];
        else {
            t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }
}

cout << t[m][n] << "\n";

//---------------------------------------


/*
1.
Ques : LONGEST COMMON Substring

Time : n^2
Space: n^2
 */

//Code-----------------------------------

int t[1001][1001];

// bottom-up


//top-down
int lcsubstring(int m, int n, int c, string &x, string &y) {
    int result = -1;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (x[i - 1] == y[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
                result = max(result, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return result;
}

//---------------------------------------

/*Graphs*/
/*
hamiltonian path & cycles

code is similar to "print all the paths in a graph from src to dest"
*/

//code
public class Main {
    public static void hamiltonianPC(int src, ArrayList<Edge>[] graph,
                                     HashSet<Integer> visited, String psf, int osrc) {
        //when all the vertices are visited - (base case)
        if (visited.size() == graph.length - 1) {
            boolean isClosedPath = false;
            System.out.print(psf);  //psf = path so far
            for (Edge e : graph[src]) {
                if (e.nbr == osrc) {
                    //the path is closed => cycle
                    isClosedPath = true;
                    break;
                }
            }

            if (isClosedPath) {
//the graph has a cycle (last node is connected to start node) => hamiltonian cycle.
                System.out.println("*");
            }
            else
                System.out.println(".");

            return;
        }


        visited.add(src);
        for (Edge edge : graph[src]) {
            if (visited.contains(edge.nbr) == false) {
                hamiltonianPC(edge.nbr, graph, visited, psf + edge.nbr, osrc);
            }
        }

        visited.remove(src);
    }

    public static void main(String[] args) throws Exception {

        // write all your codes here
        HashSet<Integer> visited = new HashSet<>();
        hamiltonianPC(src, graph, visited, src + "", src);
    }


}

//---------------------------------------

//is it a Bipartite graph:A graph is called bipartite if it is possible to split it's vertices in two sets of mutually
//exclusive and exhaustive vertices such that all edges are across sets.

//code

/*
testcases:

*/

//---------------------------------------

/*
3. is graph cyclic?
*/

//code
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

    public static boolean isCyclicHelper(int v, ArrayList < Edge > [] graph, boolean[] visited, int parent) {
        visited[v] = true;

        for (Edge edge : graph[v]) {
            if (!visited[edge.nbr]) {
                if (isCyclicHelper(edge.nbr, graph, visited, v)) {
                    return true;
                }
            } else {
                //if an adj node isn't a parent of the current vertex v,
                // then its a cycle
                if (edge.nbr != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    public static boolean isCyclic(ArrayList < Edge > [] graph) {
        boolean[] visited = new boolean[graph.length];

        for (int v = 0; v < graph.length; v++) {
            if (!visited[v]) {
                if (isCyclicHelper(v, graph, visited, -1))
                    return true;
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList < Edge > [] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList < > ();
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
        System.out.println(isCyclic(graph));
    }
}

//---------------------------------------


/*
4.  does a path exists b/w source and destination?
*/

public static boolean hasPath(int src, int dest, ArrayList < Edge > [] graph, boolean visited[]) {
    if (src == dest) {
        return true;
    }

    visited[src] = true;

    for (Edge val : graph[src]) {
        if (visited[val.nbr] == false) {
            boolean result = hasPath(val.nbr, dest, graph, visited);
            if (result == true) {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------------------------


/*print all the connected components of a graph */
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

    public static void connectedComponents(int vertex, ArrayList < Edge > [] graph, boolean[] visited, ArrayList < Integer > compo) {
        visited[vertex] = true;
        compo.add(vertex);

        for (Edge edge : graph[vertex]) {
            if (visited[edge.nbr] == false) {
                connectedComponents(edge.nbr, graph, visited, compo);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList < Edge > [] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList < > ();
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

        ArrayList < ArrayList < Integer >> comps = new ArrayList < > ();

        // write your code here
        boolean[] visited = new boolean[vtces];
        for (int node = 0; node < vtces; node++) {
            if (visited[node] == false) {
                ArrayList < Integer > compo = new ArrayList<>();
                connectedComponents(node, graph, visited, compo);
                comps.add(compo);
            }

        }
        System.out.println(comps);
    }
}
/*
testcases:
input:
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

output:
[[0, 1], [2, 3], [4, 5, 6]]
*/
//---------------------------------------------------------------------------

/* BFS of a graph */
public static void bfs(int src, ArrayList<Edge>[] graph, boolean[] visited) {
    Queue<Pair> q = new ArrayDeque<>();
    q.add(new Pair(src, src + ""));
    visited[src] = true;
    Pair top = new Pair(0, "");
    while (q.size() != 0) {
        top = q.poll();
        System.out.println(top.v + "@" + top.psf);

        for (Edge edge : graph[top.v]) {
            if (!visited[edge.nbr]) {
                visited[edge.nbr] = true;
                q.add(new Pair(edge.nbr, top.psf + edge.nbr));
            }
        }
    }

}

/*
testcases:
input:
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
2

output:
2@2
1@21
3@23
0@210
4@234
5@2345
6@2346
*/
//---------------------------------------------------------------------------

/*  */

/*
testcases:
input:


output:

*/
//---------------------------------------------------------------------------

//temp code isbipartite
class Solution {
    public class Pair {
        int v, level;

        Pair(int nv, int nlevel) {
            v = nv;
            level = nlevel;
        }
    }

    public boolean isCompBipartite(int v, ArrayList<Integer>[] g, int[] visited) {
        ggf
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(v, 1));

        while (q.size() > 0) {
            Pair top = q.remove();
            if (visited[top.v] != -1) {
                //already visited

            }
            else {
                visisted[top.v] = true;
            }

            for (Integer node : g[top.v]) {
                if (!visited[node]) {
                    q.add(new Pair(node, top.level + 1));
                }
            }
        }
    }

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] visited = new int[n];
        Arrays.fill(visited, -1);

        ArrayList<Integer>[] g = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            g[graph[i][0]].add(graph[i][1]);
            g[graph[i][1]].add(graph[i][0]);
        }

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                boolean isbp = isCompBipartited(v, g, visited);
                if (!isbp) {
                    return false;
                }
            }
        }
        return true;
    }
}

//----------------------------------------------------------------

/*
dijkstra's algorithm: the shortest path from a node to all the other nodes in the graph.
time: O(|V| + |E|*Log(|V|)) cuz it uses BFS to traverse the whole graph and log(V)  = time to
heapify the min-heap (priority queue) with |V| number of vertices because we r only storing the
vertices in the priority-queue which r not visited yet and at max we have only |V| number of
vertices.
*/
public static class Pair implements Comparable<Pair> {
    int v, dist;
    String path;
    Pair(int nv, String npath, int ndist) {
        v = nv;
        path = npath;
        dist = ndist;
    }

    public int compareTo(Pair a) {
        return this.dist - a.dist;
    }
}

public static void shortestPath(int src, ArrayList<Edge>[] graph) {
    boolean[] visited = new boolean[graph.length];
    Queue<Pair> pq = new PriorityQueue<>();

    pq.add(new Pair(src, src + "", 0));
    // visited[src] = true;

    while (pq.size() > 0) {
        Pair top = pq.remove(); //step1: remove
        if (visited[top.v]) {
            /*
            ("continue" it) else u will print the node which is already visited.
            */
            continue;
        }
        else
            visited[top.v] = true;  //step2: make true
        //step3: print
        System.out.println(top.v + " via " + top.path + " @ " + top.dist);
        for (Edge e : graph[top.v]) {
            if (!visited[e.nbr]) {
                //step4: add to pq
                pq.add(new Pair(e.nbr, top.path + e.nbr, top.dist + e.wt));
            }
        }
    }

}

public static void main(String[] args) throws Exception {
    int src = Integer.parseInt(br.readLine());
    // write your code here
    shortestPath(src, graph);

}
}


//----------------------------------------------------------------

/*
Prim's algorithm for min-spanning tree: (connected graph with minimum total-cost of all the edges.
i.e. mininum cost to traverse all the vertices in a graph.)

time: O(|V| + |E|*Log(|V|)) cuz it uses BFS to traverse the whole graph and log(V)  = time to
heapify the min-heap (priority queue) with |V| number of vertices because we r only storing the
vertices in the priority-queue which r not visited yet and at max we have only |V| number of
vertices.
*/

public class Main {
    public static class Pair implements Comparable<Pair> {
        int v, parent, wt;
        Pair(int nv, int nparent, int nwt) {
            v = nv;             //vertex number
            parent = nparent;   //parent of a given vertex
            wt = nwt;           //weight
        }

        public int compareTo(Pair other) {
            return this.wt - other.wt;  //if(this.wt > other.wt) then min-heap
        }
    }

    public static void main(String[] args) throws Exception {

        // write your code here
        //prims algorithm for minimum spanning tree.
        Queue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(0, -1, 0));
        boolean[] visited = new boolean[vtces];

        while (pq.size() > 0) {
            Pair top = pq.remove();

            if (visited[top.v]) //so that the last remaining nodes dont gets added to the spanning tree.
                continue;
            else
                visited[top.v] = true;
            if (top.v != 0) // dont print from the initial node.
                System.out.println("[" + top.v + "-" + top.parent + "@" + top.wt + "]");
            for (Edge edge : graph[top.v]) {
                if (!visited[edge.nbr]) {
                    pq.add(new Pair(edge.nbr, top.v, edge.wt));
                }
            }
        }
    }

}

//------------------------------------------------------------------------------------------

/*
topological sort

Time Complexity: O(V+E).
The above algorithm is simply DFS with an extra stack.
So time complexity is the same as DFS which is O(V+E).
*/

public class Main {

    // DFS call to the graph for topological sort.
    public static void tsUtil(int v, ArrayList<Edge>[] graph, boolean[] visited,
                              Stack<Integer> stk) {
        visited[v] =  true;
        for (Edge e : graph[v]) {
            if (!visited[e.nbr]) {
                tsUtil(e.nbr, graph, visited, stk);
            }
        }
        stk.push(v);
    }

    public static void topologicalSort(int src, ArrayList<Edge>[] graph) {
        boolean[] visited = new boolean[graph.length];
        Stack<Integer> stk = new Stack<>();
        for (int v = 0; v < graph.length; v++) {
            if (!visited[v]) {
                tsUtil(v, graph, visited, stk);
            }
        }

        while (stk.size() > 0) {
            System.out.println(stk.pop());
        }
    }

    public static void main(String[] args) throws Exception {
        // write your code here
        topologicalSort(0, graph);
    }

}

//------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------
//recursion

/*
Tower of Hanoi:
total number of iterations to complete the shifting of N disks from A to B = (2^N - 1)


Take an example for 2 disks :
Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

Step 1 : Shift first disk from 'A' to 'B'.
Step 2 : Shift second disk from 'A' to 'C'.
Step 3 : Shift first disk from 'B' to 'C'.

The pattern here is :
Shift 'n-1' disks from 'A' to 'B'.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C'.
*/

static void towerOfHanoi(int n, char from_rod,
                         char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); // toh(n-1, 1st, 3rd, 2nd);
    System.out.println("Move disk " + n + " from rod " +
                       from_rod + " to rod " + to_rod );
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); // toh(n-1, 3rd, 2nd, 1st);
}

//---------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------
//recursion

/*
find all the indexes of x in array - arr
find the count of x in arr, and then in tail recursion
use that freqeuncy fsf as an index to store the required indices
*/

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int x = Integer.parseInt(br.readLine());
        int[] iarr = allIndices(arr, x, 0, 0);

        if (iarr.length == 0) {
            System.out.println();
            return;
        }

        for (int i = 0; i < iarr.length; i++) {
            System.out.println(iarr[i]);
        }
    }

    //fsf = frequency of the x so far in the array- arr
    public static int[] allIndices(int[] arr, int x, int idx, int fsf) {
        // write ur code here
        if (idx == arr.length) {
            return new int[fsf];
        }
        int res[];
        if (arr[idx] == x) {
            res = allIndices(arr, x, idx + 1, fsf + 1);
            res[fsf] = idx;
            return res;
        }
        else {
            res = allIndices(arr, x, idx + 1, fsf);
        }

        return res;
    }
}

//---------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------
//recursion
/*question: Get Maze Path With Jumps
*/
/*
Description:
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner.
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..).
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

*/


public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList < String > res = getMazePaths(0, 0, n - 1, m - 1);
        System.out.println(res);
    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static ArrayList < String > getMazePaths(int sr, int sc, int dr, int dc) {
        if (sr == dr && sc == dc) {
            ArrayList < String > bres = new ArrayList < > ();
            bres.add("");
            return bres;
        }

        // if (sr > dr || sc > dc) {


        //     return new ArrayList < > ();
        // }

        ArrayList < String > res = new ArrayList < > ();

        for (int i = 1; sc + i < dc; i++) {
            ArrayList < String > hPath = getMazePaths(sr, sc + i, dr, dc);
            for (String val : hPath) {
                res.add("h" + i + val);
            }

        }

        for (int i = 1; sr + i < dr; i++) {
            ArrayList < String > vPath = getMazePaths(sr + i, sc, dr, dc);

            for (String val : vPath) {
                res.add("v"  + i + val);
            }
        }


        // int j = 1;
        for (int i = 1; sr + i < dr && sc + i < dc; i++) {
            ArrayList < String > dPath = getMazePaths(sr + i, sc + i, dr, dc);

            for (String val : dPath) {
                res.add("d"  + i + val);
            }
        }



        return res;
    }

}

/*
//testcases
Constraints
0 <= n <= 10
0 <= m <= 10

Sample Input
2
2
Sample Output
[h1v1, v1h1, d1]

*/

//---------------------------------------------------------------------------------------

/*
Description:
Print Stair Paths:
1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
3. Complete the body of printStairPaths function - without changing signature - to print the list of all paths that can be used to climb the staircase up.
Use sample input and output to take idea about output.

Constraints
0 <= n <= 10

Sample Input
3

Sample Output
111
12
21
3
*/

//code

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printStairPaths(n, "");
    }

    public static void printStairPaths(int n, String path) {

        if (n <= 0) {
            if (n < 0)
                return;
            System.out.println(path);
            return;
        }

        for (int i = 1; i <= 3; i++) { // at max. only 3 steps are possible so 3 iterations
            printStairPaths(n - i, path + i);
        }
    }

}

//---------------------------------------------------------------------------------------

/*
description: Maze Path
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Complete the body of pri tMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

Sample Input
2
2

Sample Output
hv
vh
*/
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        printMazePaths(0, 0, n - 1, m - 1, "");

    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    //psf - path so far
    public static void printMazePaths(int sr, int sc, int dr, int dc, String psf) {
        if (sr > dr || sc > dc) {
            return;
        }
        if (sr == dr && sc == dc) {
            System.out.println(psf);
            return;
        }
        printMazePaths(sr, sc + 1, dr, dc, psf + "h");
        printMazePaths(sr + 1, sc, dr, dc, psf + "v");
    }
}
//---------------------------------------------------------------------------------------

/*
Description:
Print Permutations

1. You are given a string str.
2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
Use sample input and output to take idea about permutations.

input:
abc

Sample Output
abc
acb
bac
bca
cab
cba
*/

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        printPermutations(str);
    }

    public static void printPermutations(String str) {
        ppUtil(str, "");
    }
    //ssf = string so far
    public static void ppUtil(String str, String ssf) {

        int n = str.length();
        if (n == 0) {
            System.out.println(ssf);
            return;
        }

        String remStr = "";
        for (int i = 0; i < n; i++) {
            remStr = str.substring(0, i) + str.substring(i + 1); //leftPart + rightPart
            ppUtil(remStr, ssf + str.charAt(i));
        }
    }

}



//---------------------------------------------------------------------------------------

/*
Description: (Recursion)
*** Print encodings:

1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
Use the input-output below to get more understanding on what is required
123 -> abc, aw, lc
993 -> iic
013 -> Invalid input. A string starting with 0 will not be passed.
103 -> jc
303 -> No output possible. But such a string maybe passed. In this case print nothing.

Constraints

0 <= str.length <= 10

Sample Input

655196

Sample Output

feeaif
feesf
*/

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        printEncodings(str);
    }

    public static void printEncodings(String str) {
        peUtil(0, str, "");
    }

    public static void peUtil(int index, String str, String psf) {
        int size = str.length();

        if (index >= size) {
            System.out.println(psf);
            return;
        }

        char curr1 = (char)(str.charAt(index) - '1' + 'a');
        // System.out.print(curr1+", ");
        char curr2 = ' ';
        int asci = 0;
        if (index != size - 1) {
            asci = Integer.parseInt(str.substring(index, index + 2));
            // System.out.print(asci+", ");
        }

        //1 character
        if (isAlp(curr1))
            peUtil(index + 1, str, psf + curr1);

        //2 chars
        if (index != size - 1 && isAlp(curr1) && asci > 0 && asci < 27) {
            curr2 = (char)(asci - 1 + 'a');
            // System.out.println(curr2);
            peUtil(index + 2, str, psf + curr2);
        }

    }

    public static boolean isAlp(char a) {
        return a >= 'a' && a <= 'z';
    }

}


//---------------------------------------------------------------------------------------

/*
Description:
maze path: backtracking

input:
3 3
0 0 0
1 0 0
0 0 0

output:
rddr
rdrd
rrdldr
rrdd

*/

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = scn.nextInt();
            }
        }

        floodfill(arr);
    }


    public static void floodfill(int[][] maze) {
        boolean visited[][] = new boolean[maze.length][maze[0].length];
        ffUtil(0, 0, "", maze.length - 1, maze[0].length - 1, maze, visited);
    }

    public static void ffUtil(int x, int y, String psf, int n, int m, int[][] maze, boolean[][] visited) {
        if (x < 0 || y < 0 || x > n || y > m || maze[x][y] == 1 || visited[x][y] == true) {
            return;
        }

        // if() return;

        if (x == n && y == m) {
            System.out.println(psf);
            return;
        }

        visited[x][y] = true;
        ffUtil(x - 1, y, psf + 't', n, m, maze, visited);
        ffUtil(x, y - 1, psf + 'l', n, m, maze, visited);
        ffUtil(x + 1, y, psf + 'd', n, m, maze, visited);
        ffUtil(x, y + 1, psf + 'r', n, m, maze, visited);

        visited[x][y] = false;
    }

}

//---------------------------------------------------------------------------------------

/*
Description:
flatten a linkedlist - method 1
time:O(N*N*M)

hint: use merge sort recursively on the current list which is already flattened
 The down pointer is used to link nodes of the flattened list.
*/

//---------------------------------------------------------------------------------------

/*
Description: mid of a linkedlist
time:O(n)
*/
public int mid() {
    // write your code here
    Node slow = head, fast = head;
    while (slow != null  && fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow.data;
}
//---------------------------------------------------------------------------------------

/*
Description:
i) Find the missing/repeated number in an array (elements may not be
from 1 to N)
space = O(1)
time = O(n)

link: https://www.techiedelight.com/find-missing-number-array/

ii) In an array, all elements are repeated twice except one element which
comes thrice, find that element. I gave him the simple XOR solution, where
we XOR all the elements and the final result is the answer.

sol:
method 1:

1. find the sum of the numbers from the smallest in the array to largest number
a. 1 to n if (values is from 1 to n)

b. range(smallest to largest)

- find the sum of this a., b. range.
- now find the sum of all the numbers from the array.
- substract both, u will get the required repeated/missing number.

method 2: using XOR
1. find the xor of the numbers from the smallest in the array to largest number
a. 1 to n if (values is from 1 to n)

b. range(smallest to largest)
2. find the xor of all the array elements with same variable as used above for 1.
3. now u will get the missing one.

cuz , X^0 = X, X^X=0


int getMissingNumber(int arr[], int n)
{
    // Compute XOR of all the elements in the array
    int xor = 0;
    for (int i = 0; i < n; i++) {
        xor = xor ^ arr[i];
    }

    // Compute XOR of all the elements from 1 to `n+1`
    for (int i = 1; i <= n + 1; i++) {
        xor = xor ^ i;
    }

    return xor;
}
*/

//---------------------------------------------------------------------------------------

/*
Description: Zig-Zag traversal
*/
class Node {
    int data;
    Node left, right;
}

void printZigZagTraversal() {
    if (rootNode == null)
        return;

    ArrayDeque<Node> q = new ArrayDeque<>();
    q.add(rootNode);

    int l = 1;  //root is taken care of
    Node temp;
    while (q.size() != 0) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {

            //pop logic
            temp = (l % 2 == 0) ? q.removeLast() : q.removeFirst();
            System.out.print(temp.data + " ");

            //push logic
            if (l % 2 == 0) {
                if (temp.right != null) {
                    q.addFirst(temp.right);
                    // System.out.print(temp.data +" ");
                }

                if (temp.left != null) {
                    q.addFirst(temp.left);
                    // System.out.print(temp.data +" ");
                }
            }
            else {
                if (temp.left != null) {
                    q.addLast(temp.left);
                    // System.out.print(temp.data +" ");
                }

                if (temp.right != null) {
                    q.addLast(temp.right);
                    // System.out.print(temp.data +" ");
                }
            }
        }

        l++;
    }
}

//---------------------------------------------------------------------------------------

/*
Description: Print Nodes K Distance Away

Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
37
2
Sample Output
12
50

*/

// code
public static void printKLevelsDown(Node node, int k, Node blocker) {
    // write your code here
if(node == null || node == blocker || k<0)
    return;
    
if(k==0) {
    System.out.println(node.data);
}
printKLevelsDown(node.left, k-1, blocker);
printKLevelsDown(node.right, k-1, blocker);
}
  
public static ArrayList<Node> nodeToRootPath(Node node, int data){
// write your code here
ArrayList<Node> curr = new ArrayList<>();
if(node == null)
    return curr;

ArrayList<Node> l = nodeToRootPath(node.left, data);
ArrayList<Node> r = nodeToRootPath(node.right, data);
if(l.size()==0 && r.size()==0 && node.data != data){
    curr.clear();
    return curr;
}

while(l.size()>0){
    curr.add(l.remove(0));
}

while(r.size()>0){
    curr.add(r.remove(0));
}
curr.add(node);

return curr;
}

public static void printKNodesFar(Node node, int data, int k) {
  if(node == null)
    return;
// write your code here
ArrayList<Node> path = nodeToRootPath(node, data);

    
for(int i=0;i<path.size() && i<=k;i++) {
    Node blocker = (i==0)? null : path.get(i-1);
    printKLevelsDown(path.get(i), k-i, blocker);
}
}

printKNodesFar(root, data, k);

//---------------------------------------------------------------------------------------

/*
Description: Remove leaves from a binary tree

*/
public static Node removeLeaves(Node node){
    // write your code here
    if(node==null)
        return null;
        
    if(node.left==null && node.right==null){
        node = null;
        return node;
    }

    node.left = removeLeaves(node.left);
    node.right = removeLeaves(node.right);
    return node;
}

//---------------------------------------------------------------------------------------

/*
Description: height of a binary tree

*/
static int res = -1;
public static int diameterUtil(Node node) {
    if(node==null){
        return -1;
    }
    
    int l= diameterUtil(node.left);
    int r = diameterUtil(node.right);
    res = Math.max(l+r+2, res); //update the max diameter.
    
    return Math.max(l,r)+1; //returns height
}
    
public static int diameter1(Node node) {
    // write your code here
    diameterUtil(node);
    return res;
}

int diameter = diameter1(root);
System.out.println(diameter);

//---------------------------------------------------------------------------------------

/*
Description: isValidBST
*/

public boolean isBstUtil(TreeNode root, long low, long high) {
    if(root == null)
        return true;

    if(root.val<=low || root.val>=high) {
        return false;
    }

    return isBstUtil(root.left, low, root.val) && isBstUtil(root.right, root.val, high);
}
public boolean isValidBST(TreeNode root) {
    return isBstUtil(root, Long.MIN_VALUE, Long.MAX_VALUE); 
}

//---------------------------------------------------------------------------------------

/*
Description: tilt of a binary tree
You are required to complete the body of tilt function. 
The function is expected to set the value of data member "tilt". 
"tilt" of a node is the absolute value of difference between sum of nodes 
in it's left subtree and right subtree. "tilt" of the whole tree is represented
as the sum of "tilt"s of all it's nodes.
*/

static int tilt = 0;
public static int tilt(Node node){
// write your code here to set the tilt data member
    if(node==null) {
        return 0;
    }
    int leftSum = tilt(node.left);
    int rightSum = tilt(node.right);
    tilt += Math.abs(leftSum - rightSum);
    return node.data + leftSum + rightSum;
}
//---------------------------------------------------------------------------------------

/*
Description:

*/

//---------------------------------------------------------------------------------------

/*
Description:

*/

//---------------------------------------------------------------------------------------

