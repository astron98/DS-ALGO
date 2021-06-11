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

void solver(int index, string ans, int tar, vector<int> &a) {
	if (index >= a.size() || tar < 0) {
		if (tar == 0)
			cout << ans.substr(0, ans.size() - 1) << ".\n";
		return;
	}

	// if (tar == 0) {
	// 	cout << ans.substr(0, ans.size() - 1) << ".\n";
	// 	return;
	// }

	solver(index + 1, ans + to_string(a[index]) + ", ", tar - a[index], a);
	solver(index + 1, ans, tar, a);
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

	int n;
	cin >> n;
	vector<int> a(n);

	// cout << "print arr: ";
	rep(i, n) {
		cin >> a[i];
		// cout << a[i] << " ";
	}
	int tar;
	cin >> tar;

	// cout << "\nn: " << n << ", tar:" << tar << "\n";

	solver(0, "", tar, a);
	return 0;
}
