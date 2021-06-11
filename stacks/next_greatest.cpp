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

	stack<int> st;
	int res[n];

	st.push(v[n - 1]);
	res[n - 1] = -1;

	repD(i, n - 2, 0) {
		if (v[i] < st.top()) {
			res[i] = st.top();
		}
		else {
			while (!st.empty() && st.top() <= v[i])
				st.pop();

			if (!st.empty()) {
				res[i] = st.top();
			}
			else {
				res[i] = -1;
			}
		}

		st.push(v[i]);
	}

	rep(i, n)
	cout << res[i] << "\n";

	// cout << '\n';
	return 0;
}

/*
Testcases:

case 1:
input:
5
5
3
8
-2
7

output:
8
8
-1
7
-1

-------------------------------
*/
