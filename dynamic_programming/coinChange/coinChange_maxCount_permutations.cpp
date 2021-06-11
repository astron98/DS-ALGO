// Created by astron98
/* 	
	CoinChange max possible permutations:	
*/



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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int n, target;
	cin >> n;
	vector<int> v(n);
	rep(i, n)
	cin >> v[i];

	cin >> target;

	int t[target + 1];
	memset(t, 0, sizeof(t));

	t[0] = 1;
	/*
	Note:i=0 is not taken coz, for target=0 there is only one possibility.
		 So need not update the (i=0)value again.
	*/
	for (int i = 1; i < target + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (v[j] <= i)
				t[i] += t[i - v[j]];
		}
	}

	printf("%d\n", t[target]);

	return 0;
}


/*
testcases:
1.
input:
18
19
18
12
8
7
12
19
12
0
17
3
5
10
8
1
11
13
20
14

output: 559

2.
*/