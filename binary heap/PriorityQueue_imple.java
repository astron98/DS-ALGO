import java.io.*;
import java.util.*;
        
public class PriorityQueue_imple {

  public static class PriorityQueue {
    ArrayList<Integer> data;

    public PriorityQueue() {
      data = new ArrayList<>();
    }
    
    public void swap(int i, int j) {
        int temp  = data.get(i);
        data.set(i, data.get(j));
        data.set(j, temp);
    }
    
    public void upHeapify(int i) {
        if(i==0)    
            return;
            
        int parent = (i-1)/2;
        if(data.get(parent)>data.get(i)) {
            //swap
            // swap(i, parent);
            int temp  = data.get(i);
            data.set(i, data.get(parent));
            data.set(parent, temp);
            upHeapify(parent);
        }
    }
    
    public void downHeapify(int i) {
        int lci = (2*i+1)/2;    //left child index
        int rci = (2*i+2)/2;    //right child index
        int n = data.size();
        int swapIdx = i;
        if(lci < n && data.get(lci)< data.get(i))
            swapIdx = lci;
        if(rci < n && data.get(rci)< data.get(i)) {
            if(data.get(rci) < data.get(lci))
                swapIdx = rci;
        }
                
        if(swapIdx!=i) {
            // swap(i, swapIdx);
            int temp  = data.get(i);
            data.set(i, data.get(swapIdx));
            data.set(swapIdx, temp);
            downHeapify(swapIdx);
        }
    }

    public void add(int val) {
      // write your code here
      data.add(val);
      upHeapify(data.size()-1);
    }

    public int remove() {
      // write your code here
      if(data.size()==0){
          System.out.println("Underflow");
          return -1;
      }
      
      int res = data.get(0);
      int lastElement = data.get(data.size()-1);    
      data.set(0, lastElement);
      data.remove(data.size()-1);
      downHeapify(0);
      return res;
    }

    public int peek() {
      // write your code here
      if(data.size()==0){
          System.out.println("Underflow");
          return -1;
      }
      
      return data.get(0);
    }

    public int size() {
      // write your code here
      return data.size();
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader("../input.txt"));
    PriorityQueue qu = new PriorityQueue();

    String str = br.readLine();
    while (str.equals("quit") == false) {
      if (str.startsWith("add")) {
        int val = Integer.parseInt(str.split(" ")[1]);
        qu.add(val);
      } else if (str.startsWith("remove")) {
        int val = qu.remove();
        if (val != -1) {
          System.out.println(val);
        }
      } else if (str.startsWith("peek")) {
        int val = qu.peek();
        if (val != -1) {
          System.out.println(val);
        }
      } else if (str.startsWith("size")) {
        System.out.println(qu.size());
      }
      str = br.readLine();
    }
  }
}