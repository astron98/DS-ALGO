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

int t[1001][1001];

int lcsubstring(int m, int n, int c, string &x, string &y) {
	int result = -1;

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (x[i - 1] == y[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
				result = max(result, t[i][j]);
			}
			else
				t[i][j] = 0;
		}
	}
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	string x, y;
	cin >> x >> y;
	memset(t, -1, sizeof(t));

	int m = x.size(), n = y.size();
	cout << lcsubstring(m, n, 0, x, y) << "\n";

	return 0;
}

/*
Testcases:

case 1:
input:

output:

-------------------------------
*/
