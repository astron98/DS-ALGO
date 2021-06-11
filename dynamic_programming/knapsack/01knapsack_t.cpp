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

int knapsack01(int wt, int n, vector<int> &v, vector<int> &w) {

	int t[n + 1][wt + 1];
	memset(t, -1, sizeof(t));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= wt; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (w[i - 1] <= j)
				t[i][j] = max(v[i - 1] + t[i - 1][j - w[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][wt];
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

	int n, cap;
	cin >> n;
	vector<int> v(n), w(n);

	rep(i, n)
	cin >> v[i];

	rep(i, n)
	cin >> w[i];

	cin >> cap;
	// vector<vector<int>> t(n + 1 , vector<int>(cap + 1, -1));

	int res = knapsack01(cap, n, v, w);

	printf("%d\n", res);
	return 0;
}
