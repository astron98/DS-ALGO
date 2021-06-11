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

int rv[] = { -2, -1, 1, 2, 2, 1, -1, -2};
int cv[] = {1, 2, 2, 1, -1, -2, -2, -1};

// bool  isPos(int row, int col, vector<vector<int>> &t) {


// }

void displayMoves(int **t, int n) {
	rep(i, n) {
		int j = 0;
		for (j = 0; j < n - 1; j++) {
			cout << t[i][j] << " ";
		}
		cout << t[i][j] << "\n";
	}

	cout << endl;
}

void solver(int n, int move , int row , int col, int **t) {
	if (move == n * n) {	//if all the boxes are visited in the chess board print them.
		t[row][col] = move;
		displayMoves(t, n);
		printf("\n");
		t[row][col] = 0;
		return;
	}

	int x, y;
	t[row][col] = move;
	rep(i, 8) {
		x = row + rv[i];
		y = col + cv[i];

		if ((x >= 0 && x < n) && (y >= 0 && y < n) && t[x][y] == 0) {
			solver(n, move + 1, x, y, t);
		}
	}
	t[row][col] = 0;
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
	int r, c;
	cin >> n >> r >> c;
	// vector<vector<int>> t(n, vector<int>(n, 0));
	int **t = new int*[n];
	rep(i, n) {
		t[i] = new int[n];
	}

	//initialization of the chess board to zero(0)
	rep(i, n) {
		rep(j, n) {
			t[i][j] = 0;
		}
	}
	int move = 1;
	// rep(0, 8) {
	// 	solver(n, move , r, c, t);
	// }

	solver(n, move , r, c, t);

	// free the memory.
	rep(i, n) {
		delete[] t[i];
	}

	delete[] t;

	return 0;
}
