// #include<iostream>
#include<bits/stdc++.h>
// #include<utility>
using namespace std;

// vector<int> result(int a[],int b[],int n,int m,int x)
// {
    
    
//     // return res;
// }


int main()
 {
	//code
	int t,n,m,x;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m>>x;
	    int a[n],b[m];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        
	   for(int i=0;i<m;i++)
	        cin>>b[i];
	   
	   //vector<pair<int,int>> res1 = result();
	   
	vector<pair<int,int>> res;
    int l1,l2;
    if(n<m)
    {
        sort(a,a+n);
        l1=m;
        l2= n;
    }
    else
    {
        sort(b,b+m);
        l1=n;
        l2=m;
    }    
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(b[j]>(x-a[i]))
                break;
            if(b[j]==(x-a[i]))
            {
                res.push_back(make_pair(a[i],b[j]));
            }
        }
    }
    
    for(int i=0;i<res.size()-1;i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<",";
    }
    // printf("%d %d \n ",a[res.size()-1].first,a[res.size()-1].second);
	cout<<res[res.size()-1].first<<" "<<res[res.size()-1].second<<"\n";        
	}
	return 0;
}
