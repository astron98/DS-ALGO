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

int climbStairs(int index, int count, vector<int> &v, int *t) {
	int n = (int)v.size();
	if (t[index] != INT_MAX) return t[index];

	if (index == n) {
		return count;
	}

	int minVal = INT_MAX;
	repA(i, 1, v[index]) {
		if (index + i <= n)
			minVal = min(minVal, climbStairs(index + i, count + 1, v, t));
	}

	if (minVal != INT_MAX)
		t[index] = minVal + 1;

	return t[index];
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
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	int *t = new int[n + 1];

	// memset(t, 0, sizeof(t));
	rep(i, n)
	t[i] = INT_MAX;
	t[n] = 0;
	climbStairs(0, 0, v, t);
	printf("%d\n", t[0]);

	return 0;
}
