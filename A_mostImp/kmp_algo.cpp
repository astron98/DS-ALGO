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

void kmpAlgo(string &txt, string &pattern) {
	int n = txt.size();
	int m = pattern.size();
	int lps[m];
	lps[0] = 0;
	int i = 1, j = 0;
	/*step 1:	creating the lps = longest common proper-prefix
			 	which is also a suffix.
	*/
	while (i < m && j < m) {
		if (pattern[j] == pattern[i]) {
			lps[i] = j + 1;
			i++;
			j++;
		}
		else {	//pattern[i]!=pattern[j]
			if (j > 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	/*step 2: match the pattern */
	i = 0, j = 0;
	while (i < n) {
		if (txt[i] == pattern[j]) {
			i++;
			j++;
		}

		if (j == m) {
			cout << "pattern found at index: " << i - j << "\n";
			j = lps[j - 1];
		}
		else if (i < n && pattern[j] != txt[i]) {
			if (j > 0) {
				j = lps[j - 1];
			}
			else {
				i++;
			}
		}
	}

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

	int t, n, m;
	cin >> t;
	string txt = "", pattern = "";
	cin.ignore();/*coz "cin" just run until "\n", and getline takes the "\n"
				   so we need to clear the previous "\n" using cin.ignore(). */
	while (t--) {
		getline(cin, txt);
		getline(cin, pattern);
		// cin >> txt;
		// cin >> pattern;
		db2(txt, pattern);
		kmpAlgo(txt, pattern);
		cout << '\n';
	}
	return 0;
}

/*
Testcases:

case 1:
input:
1
ABABDABACDABABCABAB
ABABCABAB

output:
pattern found at index: 10

-------------------------------
*/
