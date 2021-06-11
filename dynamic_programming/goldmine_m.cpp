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

int goldMine(int i, int j, vector<vector<int>> &v, vector<vector<int>> &t) {
	int n = v.size(), m = v[0].size();

	if (!(i >= 0 && i < n && j >= 0 && j < m))
		return INT_MIN;

	if (t[i][j] != 0) return t[i][j];
	if (j == m - 1)
		return v[i][j];	//reached the right end wall.

	int res = INT_MIN;
	res = max(
	          max(
	              goldMine(i - 1, j + 1, v, t),
	              goldMine(i, j + 1, v, t)),
	          goldMine(i + 1, j + 1, v, t));
	t[i][j] = (res != INT_MIN) ? v[i][j] + res : 0;

	return t[i][j];
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

	vector<vector<int>> t(n, vector<int>(m, 0));
	int res = INT_MIN;
	rep(i, n) {
		res = max(res, goldMine(i, 0, v, t));
	}
	printf("%d\n", res);

	return 0;
}
