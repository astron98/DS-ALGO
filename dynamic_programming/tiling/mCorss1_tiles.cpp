// Created by ... astron98

// m*1 tiles to tile an area of n*m with width of "m". 

#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;

    int t[n+1];
    t[1] = 1;

    for(int i=2;i<=n;i++) {
    	if(i<m)
    		t[i] = 1;
    	else if(i==m)
    		t[i] = 2;
    	else
    		t[i] = t[i-1] + t[i-m];
    }

    cout << t[n] << "\n";
    return 0;
}


/*
testcases:
case 1:
input:
39
16

output:
61
--------------------
case 2:
input 
1
7

output:
1
--------------------

*/