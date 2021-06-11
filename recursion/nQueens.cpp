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

bool isQueenSafe(int i, int j, int **t, int &n) {
	// int k = i;
	//same column
	for (int k = i - 1; k >= 0; k--) {
		if (t[k][j] == 1)
			return false;
	}

	// leftDiagonal
	for (int p = i - 1, q = j + 1; p >= 0 && q < n; p--, q++) {
		if (t[p][q] == 1)
			return false;
	}

	//reverseDiagonal
	for (int p = i - 1, q = j - 1; p >= 0 && q >= 0; p--, q--) {
		if (t[p][q] == 1)
			return false;
	}

	return true;
}

void solver(int i, int **t, string ans, int &n) {
	if (i == n) {
		cout << ans << ".\n";
		return;
	}

	rep(j, n) {
		if (isQueenSafe(i, j, t, n)) {
			t[i][j] = 1;
			string newPos = to_string(i) + "-" + to_string(j) + ", ";
			solver(i + 1, t, ans + newPos, n);
			t[i][j] = 0;
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

	int n;

	cin >> n;
	int **t = new int*[n];
	rep(i, n) {
		t[i] = new int[n];
	}


	//initialization of the 2D array.
	rep(i, n)
	rep(j, n)
	t[i][j] = 0;

	solver(0, t, "", n);


	//free the memory
	for (int i = 0; i < n; i++)
		delete[] t[i];

	delete[] t;

	return 0;
}
