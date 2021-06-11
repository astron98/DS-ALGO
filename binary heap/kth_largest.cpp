#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int a[],int n,int i)
{   
    
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left <n && a[left] > a[smallest])
        smallest = left;
    if(right <n && a[right] > a[smallest])
        smallest = right;
    if(smallest!=i)
    {
        swap(a[smallest],a[i]);
        heapify(a,n,smallest);
    }
}

void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
int main()
 {
	//code
	int t,n,k;
	cin >>t;
	while(t--)
	{
	    cin >>k>>n;
	    int a[n];
	   // for(int i=0;i<n;i++)
	   // {
	   //     cin >>a[i];
	   // } 
	   // heapSort(a,n);
	    for(int i=0;i<n;i++)
	    {
	        cin >>a[i];
	        heapSort(a,i+1);
	        if(i<k-1)
	        {
	            cout<<"-1 ";
	        }
	        else if(i>=k-1) 
	        {
	            cout<<a[i-(k-1)]<<" ";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}
