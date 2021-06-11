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

long partitionSubset(int &n, int &k) {
	long t[k + 1][n + 1];
	memset(t, 0, sizeof(t));

	repA(i, 1, k) {
		repA(j, 1, n) {
			if (j == i || i == 1)
				t[i][j] = 1;
			else if (j < i)
				t[i][j] = 0;
			else
				t[i][j] = (i * t[i][j - 1]) + t[i - 1][j - 1];
		}
	}

	return t[k][n];
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

	int n, k;
	cin >> n;
	cin >> k;

	long res = partitionSubset(n, k);

	cout << res << "\n";

	return 0;
}

/*

logic:
- recursive function
f(n,k) = k*f(n-1,k) + f(n-1, k-1)

Testcases:

case 1:
input:
4
3

output:
6
-------------------------------

case 2:
input:
19
4
output:
11259666950
-------------------------------
*/
