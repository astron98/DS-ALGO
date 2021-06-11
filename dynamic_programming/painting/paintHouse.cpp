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

int solver(int t[][3], int &n) {
	int r=t[0][0],g=t[0][1],b=t[0][2];

	for(int i=1;i<n;i++) {
		int nextR = t[i][0] + min(g,b);
		int nextG = t[i][1] + min(r,b);
		int nextB = t[i][2] + min(r,g);

		r = nextR;
		g = nextG;
		b = nextB;
	}

	return min(r,min(g,b));

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int v[n][3];
    rep(i,n) {
    	cin>>v[i][0] >> v[i][1] >> v[i][2];
    }
	// rep(i,n) cout << v[i] << "\n";
    
    cout << solver(v,n);
    cout<<'\n';
    return 0;
}


/*
testcases:
case 1:
input:
4
1 5 7
5 8 4
3 2 9
1 2 4

output:
8
--------------------
*/