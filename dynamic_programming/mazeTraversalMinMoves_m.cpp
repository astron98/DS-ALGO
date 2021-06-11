// maze traversal using memoization method DP

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

int solver(int x, int y, int **t, vector<vector<int>> &v) {
	int n = v.size(), m = v[0].size();

	if (!(x >= 0 && x < n) || !(y >= 0 && y < m))	//index out of bound
		return INT_MAX;	//path doesn't exists

	if (t[x][y] != -1) return t[x][y];

	if (x == n - 1 && y == m - 1)
		return v[x][y];

	int minV = INT_MAX;

	minV = min(minV, solver(x + 1, y, t, v));	//move down

	minV = min(minV, solver(x, y + 1, t, v));	//move right

	//t[x][y] is updated only when path exists
	t[x][y] = (minV == INT_MAX) ? -1 : minV + v[x][y];
	return t[x][y];
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

	int **t = new int*[n];
	rep(i, n)
	t[i] = new int[m];


	rep(i, n)
	rep(j, m) {
		cin >> v[i][j];
		t[i][j] = -1;
	}

	solver(0, 0, t, v);

	printf("%d\n", t[0][0]);


	rep(i, n)
	delete[] t[i];
	delete[] t;
	return 0;
}
