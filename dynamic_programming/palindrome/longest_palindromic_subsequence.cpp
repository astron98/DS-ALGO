// Created by astron98
/*
LONGEST PALINDROMIC SUBSEQUENCE
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

int t[1001][1001];

int lcs(int m, int n, string &x, string &y) {
	if (m == 0 || n == 0)
		return 0;

	if (t[m][n] != -1) return t[m][n];

	if (x[m - 1] == y[n - 1])
		t[m][n] = 1 + lcs(m - 1, n - 1, x, y);
	else
		t[m][n] = max(lcs(m - 1, n, x, y), lcs(m, n - 1, x, y));

	return t[m][n];
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

	string x, y;
	cin >> x;
	y = x;
	reverse(y.begin(), y.end());
	memset(t, -1, sizeof(t));
	// cout << lcs(x.size(), y.size(), x, y);
	int m = x.size(), n = x.size();
	rep(i, m + 1) {
		rep(j, n + 1) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else {
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);
			}
		}
	}

	cout << t[m][n] << "\n";
	return 0;
}


/*
Testcases:

case 1:
input:
agbcba

output:
5
The result is = "abcba"
-------------------------------

case 2:
input:
OldSite:GeeksforGeeks.org

output:
6

-------------------------------
*/