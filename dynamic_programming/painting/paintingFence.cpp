// Created by ... astron98
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
    int n,k;	
    cin >> n >> k;

    int same = k*1;
    int diff = k*(k-1);
    int total = same + diff;

    for(int i=3;i<=n;i++) {
    	same = diff * 1;
    	diff = total * (k-1);
    	total = same + diff;
    }

    cout << total << "\n";

    return 0;
}


/*
testcases:
case 1:
input:


output:

--------------------
*/