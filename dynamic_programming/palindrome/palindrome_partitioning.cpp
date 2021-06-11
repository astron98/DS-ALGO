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

int t[10001][10001];

bool isPalindrome(int i, int j, string &str) {

	// if(i==j) return 0;
	while ( i < j ) {
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}

	return true;
}

int solver(int i, int j, string &str) {
	if (i >= j)
		return 0;

	if ( isPalindrome(i, j, str))
		return 0;

	if (t[i][j] != -1)
		return t[i][j];

	int mn = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int leftPart = 0, rightPart = 0;
		if (i < k) {
			t[i][k] = (t[i][k] == -1) ? solver(i, k, str) : t[i][k];
			leftPart = t[i][k];
		}

		if (k + 1 < j) {
			t[k + 1][j] = (t[k + 1][j] == -1) ? solver(k + 1, j, str) : t[k + 1][j];
			rightPart = t[k + 1][j];
		}

		int tempResult = leftPart + rightPart + 1;
		mn = min(tempResult, mn);
	}

	t[i][j] = mn;

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

	string s;
	cin >> s;

	memset(t, -1, sizeof(t));

	int result = solver(0, s.length() - 1, s);

	cout << result << "\n";
	return 0;
}

/*
Hint:
- use matrix chain multi logic.

Testcases:

case 1:
input:
abaabc	// a|baab|c
output:
2
-------------------------------
case 2:

input:
ababbbabbababa

output:
3
*/
