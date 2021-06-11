// Created by astron98
//memoization method.
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

int binaryStrings(string str, int &n, vector<vector<int>> &t) {
	if (str.size() == n)
		return 1;
	int i = str.size();

	if ( i == 0 || str[i - 1] == '1') {
		if (t[i][1] != -1) return t[i][1];
		t[i][1] = binaryStrings(str + '0', n, t) + binaryStrings(str + '1', n, t);
		return t[i][1];
	}
	else {
		if (t[i][0] != -1) return t[i][0];
		t[i][0] = binaryStrings(str + '1', n, t);
		return t[i][0];

	}
}

int main()
{
////#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> t(n + 1, vector<int>(2, -1));
	int res = binaryStrings("", n, t);

	printf("%d\n", res);

	return 0;
}


/*
Testcases:

case 1:
input: 6
output: 21

logic:
each bit has two possibilities 0 or 1
here, if the previous bit is 0 then the next bit should be 1.
whereas for bit value=1, we have two choices 0 or 1.
so on...until we reach the length N.

*/
