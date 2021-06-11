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

void moreThanNbyK(vector<int> &v, int n, int k) {
	unordered_map<int, int> freq;
	for (int val : v) {
		freq[val]++;
	}
	// cout << "dbg:";
	// db2(n, k);
	int limit = n / k;
	for (auto &ptr : freq) {
		if (ptr.second > limit) {
			cout << ptr.first << " ";
		}
	}
	cout << "\n";
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

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> v(n);
		rep(i, n) cin >> v[i];

		moreThanNbyK(v, n, k);
		cout << '\n';
	}
	return 0;
}

/*
Testcases:

case 1:
input:
1
13 4
1 1 2 2 3 5 4 2 2 3 1 1 1
output:
1 2
-------------------------------
*/
