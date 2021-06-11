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

bool targetSum(int i, int target, vector<int> &v, vector<vector<bool>> &t) {
	if (target <= 0 || i == v.size()) {
		if (target == 0)
			return true;
		return false;
	}

	if (t[i][target]) return true;

	t[i][target] = targetSum(i + 1, target - v[i], v, t) || targetSum(i + 1, target, v, t);

	return t[i][target];
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

	int n, target;
	cin >> n;
	vector<int> v(n);
	rep(i, n)
	cin >> v[i];

	cin >> target;
	vector<vector<bool>> t(n, vector<bool>(target + 1, false));
	rep(i, n)
	t[i][0] = true;
	bool res = false;
	res = targetSum(0, target, v, t);
	if (res)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
