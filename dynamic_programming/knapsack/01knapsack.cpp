// Created by astron98
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<''
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<''
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<''
#define rep(i,n) for(int i=0;i< (int)(n);++i)
#define repA(i,a,n) for(int i=a;i<= (int)(n);++i)
#define repD(i,a,n) for(int i=a;i>= (int)(n);--i)
#define PI pair<int,int>
typedef long long ll;

using namespace std;

int knapsack01(int wt, int n, vector<int> &v, vector<int> &w, vector<vector<int>> &t) {
	if (n == 0 || wt == 0) {
		t[n][wt] = 0;
		return 0;
	}

	if (t[n][wt] != -1) return t[n][wt];

	if (w[n - 1] <= wt)
		t[n][wt] = max(v[n - 1] + knapsack01(wt - w[n - 1], n - 1, v, w, t),
		               knapsack01(wt, n - 1, v, w, t));
	else
		t[n][wt] = knapsack01(wt, n - 1, v, w, t);

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
	vector<vector<int>> t(n + 1 , vector<int>(cap + 1, -1));

	int res = knapsack01(cap, n, v, w, t);

	printf("%d\n", res);
	return 0;
}

/*
testcases:

case 1:
input :
5
15 14 10 45 30
2 5 1 3 4
7

output: 75

case 2:

*/