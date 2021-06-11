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

int climbStairs(int index, vector<int> &v, int &n, int *t) {
	if (index > n) return 0;
	if (t[index] != 0) return t[index];

	if (index == n) return 1;

	repA(i, 1, v[index]) {
		t[index] += climbStairs(index + i, v, n, t);
	}

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

	memset(t, 0, sizeof(t));

	printf("%d\n", climbStairs(0, v, n, t));

	// cout << "\n";
	return 0;
}
