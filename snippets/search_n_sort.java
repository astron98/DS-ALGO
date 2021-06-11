//---------------------------------------------------------------------------------------

/*
Description: Target sum pair

Sample Input
12
9 
-48 
100 
43 
84 
74 
86 
34 
-37 
60 
-29 
44
160

Sample Output
60, 100
74, 86
*/

//code
public static void targetSumPair(int[] arr, int target){
    //write your code here
    Arrays.sort(arr);   // O(nlogn)
    int i=0, j=arr.length-1;
    while(i < j) {
        if(arr[i]+arr[j] < target) {
            i++;
        }
        else if(arr[i] + arr[j] > target)
            j--;
        else {
            System.out.println(arr[i] + ", " + arr[j]);
            i++; j--;
        }
    }
  }

//---------------------------------------------------------------------------------------

/*
Description: Pivot In Sorted And Rotated Array

Sample Input
9
15
16
19
21
23
24
1
2
12

Sample Output
1
*/

public static int findPivot(int[] arr) {
    // write your code here
    /*
    - if arr[rhs]<arr[mid] then min-val will lie in rhs
    else if arr[rhs]>arr[mid] then min-val will lie in lhs
    else if(i==j) means we have found the min-val, so return its value.
    */
    int i=0, j = arr.length-1, mid = (i+j)/2;
    while(i<=j) {
        mid = (i+j)/2;
        if(arr[j]<arr[mid])
            i = mid+1;
        else if(arr[j]>arr[mid])
            j = mid;
        else if(i==j)
            return arr[mid];
    }
    return -1;
  }

//---------------------------------------------------------------------------------------

/*
Description: Insertion sort
time: O(N**2)
space: O(1)
*/

public static void insertionSort(int[] arr) {
    //write your code here
    for(int i=1;i<arr.length;i++) {
        for(int j=i-1;j>=0;j--) {
            if(isGreater(arr, j, j+1))
                swap(arr, j, j+1);
            else
                break;
        }
    }
}

//---------------------------------------------------------------------------------------

/*
Description: Merge sort
time: O(N*logN)
space: O(N)
*/
public static int[] mergeSort(int[] arr, int lo, int hi) {
    //write your code here
    if(lo < hi) {
        int mid = (lo+hi)/2;
        int[] lft = mergeSort(arr, lo, mid);
        int[] rgt = mergeSort(arr, mid+1, hi);
        int[] res = mergeTwoSortedArrays(lft, rgt);
        return res;
    }
    return new int[]{arr[lo]};  // if(lo==hi)
}

//used for merging two sorted arrays
public static int[] mergeTwoSortedArrays(int[] a, int[] b){
    System.out.println("Merging these two arrays ");
    System.out.print("left array -> ");
    print(a);
    System.out.print("right array -> ");
    print(b);
    int i = 0, j =0, k = 0;
    int[] ans = new int[a.length + b.length];
    while(i < a.length && j < b.length){
        if(a[i] <= b[j]){
          ans[k] = a[i];
          i++;
          k++;
        }else{
          ans[k] = b[j];
          j++;
          k++;
        }
    }

    while(i < a.length){
      ans[k] = a[i];
      k++;
      i++;
    }

    while(j < b.length){
      ans[k] = b[j];
      k++;
      j++;
    }

    return ans;
}

//---------------------------------------------------------------------------------------

/*
Description: Quick sort
time: O(N*logN)
space: O(1)
*/

public static void quickSort(int[] arr, int lo, int hi) {
    //write your code here
    if(lo>hi){
        return;
    }
    int pivot = partition(arr, arr[hi], lo, hi);
    quickSort(arr, lo, pivot-1);
    quickSort(arr, pivot+1, hi);
  }

  /*
    0 to j-1    (<= pivot)
    j to i-1    (>  pivot)
    >= i        (unknown values)
  */
  public static int partition(int[] arr, int pivot, int lo, int hi) {
    System.out.println("pivot -> " + pivot);
    int i = lo, j = lo;
    while (i <= hi) {
      if (arr[i] <= pivot) {
        swap(arr, i, j);
        i++;
        j++;
      } else {
        i++;
      }
    }
    System.out.println("pivot index -> " + (j - 1));
    return (j - 1);
  }

//---------------------------------------------------------------------------------------

/*
Description: Merge sort
time: 
space:
*/
