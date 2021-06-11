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

int solver(string &str) {
	int n = str.size();
	int aCount=0,bCount=0,cCount=0;
	for(const char &c:str) {
		if(c=='a')
			aCount = 2*aCount + 1;
		else if(c=='b')
			bCount = 2*bCount + aCount;
		else
			cCount = 2*cCount + bCount;
	}

	return cCount;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
   	string str="";
   	cin >> str;

   	cout << solver(str) << "\n";

    return 0;
}