// Created by astron98
/*
	CoinChange max possible combinations:
		(or)
	max. possible ways. to get a sum.
*/

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

//memoization method.
int solver(int n, int target, vector<int> &v, vector<vector<int>> &t) {
	if (n == 0 || target == 0) {
		if (target == 0)
			return 1;
		return 0;
	}

	if (t[n][target] != -1)
		return t[n][target];

	if (v[n - 1] <= target) {
		t[n][target] = solver(n, target - v[n - 1], v, t) + solver(n - 1, target, v, t);
	}
	else
		t[n][target] = solver(n - 1, target, v, t);

	return t[n][target];
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

	int n, target;
	cin >> n;
	vector<int> v(n);
	rep(i, n)
	cin >> v[i];

	cin >> target;


	//tabulation method
	// int t[target + 1];
	// memset(t, 0, sizeof(t));

	// t[0] = 1;

	// rep(i, n) {
	// 	repA(j, v[i], target) {
	// 		t[j] += t[j - v[i]];
	// 	}
	// }

	// printf("%d\n", t[target]);

	vector<vector<int>> t(n + 1, vector<int>(target + 1, -1));

	t[n][target] = solver(n, target, v, t);

	printf("%d\n", t[n][target]);

	return 0;
}


/*
method 2: (note: it doesn't works with coin value as 0)

int t[n + 1][target + 1];
	memset(t, 0, sizeof(t));

	for (int i = 0; i < n + 1; i++) {
		for(int j, j < target + 1; j++) {
			if (j == 0)
				t[i][j] = 1;
			else if (i == 0)
				t[i][j] = 0;
			else {
				if (v[i - 1] <= j) {
					t[i][j] = t[i - 1][j] + t[i][j - v[i - 1]];
				}
				else
					t[i][j] = t[i - 1][j];
			}
		}
	}

*/