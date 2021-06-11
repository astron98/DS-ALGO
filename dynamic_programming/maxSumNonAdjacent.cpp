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

int solver(int n, bool flag, vector<int> &v, int t[][2]) {
	if(n==v.size())
		return 0;

	if(t[n][0]!=-1 && t[n][1]!=-1){
		if(flag)
			return t[n][0];
		return t[n][1];
	}

	if(flag) {
		t[n][0] = solver(n+1,!flag,v,t);
	}
	else
		t[n][1] = max(v[n] + solver(n+1,!flag,v,t), solver(n+1, flag, v,t));
	return (flag)? t[n][0]:t[n][1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n) cin>>v[i];
	
	int t[n+1][2]; memset(t,-1,sizeof(t));
    cout << solver(0,false,v,t) << "\n";

    cout<<'\n';
    return 0;
}

/*
testcases:
case 1:
input:
6
5
10
10
100
5
6

output:
116
--------------------
*/