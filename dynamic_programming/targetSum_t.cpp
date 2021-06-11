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

	int n, target;
	cin >> n;
	vector<int> v(n);
	rep(i, n)
	cin >> v[i];

	cin >> target;
	bool t[n + 1][target + 1];

	rep(i, n + 1) {
		rep(j, target + 1) {
			if (i == 0 && j == 0)
				t[i][j] = true;
			else if (j == 0)
				t[i][j] = true;
			else if (i == 0)
				t[i][j] = false;
			else {
				/*
				case 1: if curr target can be made by previous elements return true
				case 2: if target = (value scored by current element) +  (previous elements) return true;

				return case1 || case2;
				*/
				t[i][j] = t[i - 1][j] || ((j >= v[i - 1]) ? t[i - 1][j - v[i - 1]] : false);
			}
		}
	}

	bool res = t[n][target];

	if (res)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
