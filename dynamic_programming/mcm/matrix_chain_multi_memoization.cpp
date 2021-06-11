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

int t[1001][1001];

int mcm(int i, int j, int a[]) {
	if (i >= j)
		return 0;
	if (t[i][j] != -1)
		return t[i][j];

	int minVal = INT_MAX;

	for (int k = i; k <= j - 1; k++) {
		int tempResult = mcm(i, k, a) + mcm(k + 1, j, a) +
		                 a[i - 1] * a[k] * a[j];

		minVal = min(tempResult, minVal);
	}

	t[i][j] = minVal;

	return t[i][j];
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

	int n;
	cin >> n;
	int a[n];
	rep(i, n)
	cin >> a[i];

	memset(t, -1, sizeof(t));
	int result = mcm(1, n - 1, a);

	cout << result << "\n";

	return 0;
}

/*
Testcases:

case 1:
input:
3	//n
1	// A1...An
2
3
output:
6
-------------------------------

case 2:
input:
5	//n
1	// A1...An
2
3
4
3
output:
30
-------------------------------
*/
