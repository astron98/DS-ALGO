// Created by astron98
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i< (int)(n);++i)
#define repA(i,a,n) for(int i=a;i<= (int)(n);++i)
#define repD(i,a,n) for(int i=a;i>= (int)(n);--i)
#define PI pair<int,int>
typedef long long ll;

using namespace std;

int friendPairing(int &n) {
	int pairIt = 2;	//total pairs for 2 persons
	int dontPair = 1;	//total pairs for 1 person
	for (int i = 3; i <= n; i++) {
		int temp = pairIt + (i - 1) * dontPair;
		dontPair = pairIt;
		pairIt = temp;
	}

	return pairIt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int n;
	cin >> n;

	int res = friendPairing(n);

	cout << res << "\n";

	return 0;
}

/*
logic:

recursive function: f(n) = f(n-1) + (n-1)*f(n-2);

Testcases:

case 1:
input:
4

output:
10
-------------------------------


case 2:
input:
3

output:
4
-------------------------------

*/
