import java.io.*;
import java.util.*;
    
    
public class hashmap_implem {
  public static class HashMap<K, V> {
    private class HMNode {
      K key;
      V value;

      HMNode(K key, V value) {
        this.key = key;
        this.value = value;
      }
    }

    private int size;
    private LinkedList<HMNode>[] buckets;

    public HashMap() {
      initBuckets(4);
      size = 0;
    }

    /*
      methods:
      initBuckets(n)
      put(key, value)
      get(key)
      remove(key)
      keySet()
      size()
      display()
    */

    public void initBuckets(int n) {
      buckets = new LinkedList[n];
      for(int bi = 0; bi<buckets.length; bi++) {
        buckets[bi] = new LinkedList<>();
      }
    }

    public void put(K key, V value) throws Exception {
        int bi = hashFn(key);   //bi = bucket index
        int di = getIndexWithinBucket(key, bi); //data index 

        if(di!=-1) {
            HMNode node = buckets[bi].get(di);
            node.value = value;
        }
        else {
            //insert a new (key, value) pair in the end of the bucket list
            buckets[bi].add(new HMNode(key, value));
            size++;
        }

        double lambda = size*1.0 / buckets.length;
        if(lambda > 2.0) {
            rehash();
        }
    }

    private int hashFn(K key) {
        int hc = key.hashCode();    //generate the hashCode for the Key
        return Math.abs(hc)%buckets.length; //returns the bucket index 
    }

    private int getIndexWithinBucket(K key, int bi) {
        int di = 0; 
        for(HMNode node : buckets[bi]) {
            if(node.key.equals(key)) {
                return di;
            }
            di++;
        }

        return -1;
    }

    public V get(K key) throws Exception {
        int bi = hashFn(key);   //bi = bucket index
        int di = getIndexWithinBucket(key, bi); //data index 

        if(di!=-1) {
            HMNode node = buckets[bi].get(di);
            return node.value;
        }
        else {
            return null;
        }
    }

    public boolean containsKey(K key)  throws Exception{
        int bi = hashFn(key);   //bi = bucket index
        int di = getIndexWithinBucket(key, bi); //data index 

        return di != -1;    //if di==-1 return false, else true
    }

    public void rehash() throws Exception {
        LinkedList<HMNode>[] oldBuckets = buckets;
        initBuckets(oldBuckets.length*2);
        size = 0;
        for(int i=0; i<oldBuckets.length; i++) {
            for(HMNode node : oldBuckets[i]) {
                put(node.key, node.value);
            }
        }
    }

    public V remove(K key) throws Exception {
        int bi = hashFn(key);   //bi = bucket index
        int di = getIndexWithinBucket(key, bi); //data index 

        if(di!=-1) {
            HMNode node = buckets[bi].remove(di);
            size--;
            return node.value;
        }
        else {
            return null;
        }
    }

    public ArrayList<K> keySet() throws Exception {
        ArrayList<K> keys = new ArrayList<>();
        for(int bi=0; bi<buckets.length; bi++) {
            for(HMNode node : buckets[bi]) {
                keys.add(node.key);
            }
        }

        return keys;
    }

    public int size() {
        return size;
    }

    public void display() {
        System.out.println("Display Begins");
        for (int bi = 0; bi < buckets.length; bi++) {
          System.out.print("Bucket" + bi + " ");
          for (HMNode node : buckets[bi]) {
            System.out.print( node.key + "@" + node.value + " ");
          }
          System.out.println(".");
        }
        System.out.println("Display Ends");
    }
  }


  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader("../input.txt"));
    HashMap<String, Integer> map = new HashMap();

    String str = br.readLine();
    while (str.equals("quit") == false) {
      if (str.startsWith("put")) {
        String[] parts = str.split(" ");
        String key = parts[1];
        Integer val = Integer.parseInt(parts[2]);
        map.put(key, val);
      } else if (str.startsWith("get")) {
        String[] parts = str.split(" ");
        String key = parts[1];
        System.out.println(map.get(key));
      } else if (str.startsWith("containsKey")) {
        String[] parts = str.split(" ");
        String key = parts[1];
        System.out.println(map.containsKey(key));
      } else if (str.startsWith("remove")) {
        String[] parts = str.split(" ");
        String key = parts[1];
        System.out.println(map.remove(key));
      } else if (str.startsWith("size")) {
        System.out.println(map.size());
      } else if (str.startsWith("keyset")) {
        System.out.println(map.keySet());
      } else if (str.startsWith("display")) {
        map.display();
      }
      str = br.readLine();
    }

    br.close();
  }
}
