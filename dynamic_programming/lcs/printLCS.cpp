// Created by astron98
/*
LONGEST COMMON SUBSEQUENCE
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

//tabulation method 1: time complexity O(N^3) because we store string in the dp

// string lcs(int m, int n, string &x, string &y) {
// 	if (m == 0 || n == 0)
// 		return "";
// 	string temp = t[m][n];
// 	if (temp != "") return t[m][n];

// 	if (x[m - 1] == y[n - 1])
// 		t[m][n] += lcs(m - 1, n - 1, x, y) + x[m - 1];
// 	else {
// 		string s1 = lcs(m - 1, n, x, y);
// 		string s2 = lcs(m, n - 1, x, y);
// 		if (s1.size() >= s2.size()) {
// 			t[m][n] += s1;
// 		}
// 		else
// 			t[m][n] += s2;
// 	}

// 	return t[m][n];
// }


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
	cin >> x >> y;
	int m = x.size(), n = y.size();

	memset(t, -1, sizeof(t));

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

//tabulation method 2: time: O(N^2)
	string result = "";
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (x[i - 1] == y[j - 1]) {
			result = x[i - 1] + result;
			i--; j--;
		}
		else {
			if (t[i - 1][j] > t[i][j - 1])
				i--;
			else
				j--;
		}
	}

	cout << result << "\n";

	return 0;
}
//tabulation method 1:
/*
	string lcs(int m, int n, string &x, string &y) {
	if (m == 0 || n == 0)
		return "";
	string temp = t[m][n];
	if (temp != "") return t[m][n];

	if (x[m - 1] == y[n - 1])
		t[m][n] += lcs(m - 1, n - 1, x, y) + x[m - 1];
	else {
		string s1 = lcs(m - 1, n, x, y);
		string s2 = lcs(m, n - 1, x, y);
		if (s1.size() >= s2.size()) {
			t[m][n] += s1;
		}
		else
			t[m][n] += s2;
	}

	return t[m][n];
}

*/


/*
Testcases:

case 1:
input:
pepcoding
pepcoder

output:
pepcod
-------------------------------

case 2:
input:
OldSite:GeeksforGeeks.org
NewSite:GeeksQuiz.com

output:
Site:Geeks.o
-------------------------------

*/
