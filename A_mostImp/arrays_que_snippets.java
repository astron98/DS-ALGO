/*
Question: Rearrange an array with O(1) extra space 

Approach: The array elements of the given array lies from 0 to n-1. Now an array element is 
needed that can store two different values at the same time. To achieve this increment every 
element at ith index is incremented by (arr[arr[i]] % n)*n.After the increment operation of 
first step, every element holds both old values and new values. Old value can be obtained by 
arr[i]%n and a new value can be obtained by arr[i]/n.
*/

static void arrange(long arr[], int n)
    {
        // your code here
        long b = 0;
        for(int i=0;i<n;i++) {
            //step 1:
            b = arr[(int)arr[i]];
            arr[i] += (b%n)*n;
        }
        
        for(int i=0;i<n;i++) {
            //step 2:
            arr[i] /=n;
        }
    }

//---------------------------------------------------------------

/*
Question: 

Approach: 
*/



//---------------------------------------------------------------