// maze traversal using tabulation method DP

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

int solver(vector<vector<int>> &v) {
	int n = v.size(), m = v[0].size();

	int t[n][m];
	memset(t, 0, sizeof(t));

	repD(i, n - 1, 0) {
		repD(j, m - 1, 0) {
			if (i == n - 1 && j == m - 1)
				t[i][j] = v[i][j];
			else if (i == n - 1)
				t[i][j] = v[i][j] + t[i][j + 1];
			else if (j == m - 1)
				t[i][j] = v[i][j] + t[i + 1][j];
			else
				t[i][j] = v[i][j] + min(t[i + 1][j], t[i][j + 1]);
		}
	}

	return t[0][0];
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
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<int>> v(n, vector<int>(m));

	rep(i, n)
	rep(j, m) {
		cin >> v[i][j];
	}

	printf("%d\n", solver(v));

	return 0;
}
