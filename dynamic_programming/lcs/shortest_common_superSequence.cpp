// Created by astron98
/*
SCS (shortest common superSequence)
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
	// db2(x, y);	//debugging input values
	int m = x.size(), n = y.size();
	// db2(m, n);	//debugging	input size
	int t[m + 1][n + 1];
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

// printing the SCS (shortest common superSequence)
	string result = "";
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (x[i - 1] == y[j - 1]) {
			result.push_back(x[i - 1]);
			i--;
			j--;
		}
		else {
			if (t[i - 1][j] > t[i][j - 1]) {
				result.push_back(x[i - 1]);
				i--;
			}
			else {
				result.push_back(y[j - 1]);
				j--;
			}
		}
	}

	while (i > 0) {
		result.push_back(x[i - 1]);
		i--;
	}

	while (j > 0) {
		result.push_back(y[j - 1]);
		j--;
	}



	reverse(result.begin(), result.end());
	cout << result << "\n";

	return 0;
}


/*
Testcases:

case 1:
input:
AGGTAB
GXTXAYB

output:
AGGXTXAYB
-------------------------------

*/