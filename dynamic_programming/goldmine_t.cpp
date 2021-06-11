// Created by astron98

//goldmine in tabulation method DP
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

int goldmine_t(vector<vector<int>> &v) {
	int n = v.size(), m = v[0].size();

	int t[n][m];
	memset(t, 0, sizeof(t));

	for (int j = m - 1; j >= 0; j--) {
		for (int i = n - 1; i >= 0; i--) {
			if (j == m - 1)
				t[i][j] = v[i][j];
			else if (i == n - 1)
				t[i][j] = v[i][j] + max(t[i][j + 1], t[i - 1][j + 1]);
			else if (i == 0)
				t[i][j] = v[i][j] + max(t[i][j + 1], t[i + 1][j + 1]);
			else
				t[i][j] = v[i][j] + max(max(t[i - 1][j + 1], t[i][j + 1]), t[i + 1][j + 1]);
		}
	}


	int res = t[0][0];
	rep(i, n) {
		res = max(res, t[i][0]);	//comparison among all the entries in the left-end wall.
	}

	return res;
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

	int res = goldmine_t(v);
	printf("%d\n", res);

	return 0;
}
