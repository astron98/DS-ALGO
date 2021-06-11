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

int t[101][101];

void print(std::vector<int> &res) {
	for (int x : res)
		printf("%d ", x );
	printf("\n");
}

void printSubsetSum(int v[], int n, int sum, std::vector<int> &res) {
	if (n == 1 && sum != 0 && t[1][sum]) {
		res.push_back(v[n - 1]);
		print(res);
		return;
	}

	if (n == 1 && sum == 0) {
		print(res);
		return;
	}

	if (t[n][sum] > 0) {
		std::vector<int> temp = res;
		printSubsetSum(v, n - 1, sum, temp);
	}

	if (v[n - 1] <= sum && t[n][sum - v[n - 1]] > 0 ) {
		res.push_back(v[n - 1]);
		printSubsetSum(v, n - 1, sum - v[n - 1], res);
	}
}

int subSetSum(int v[], int n, int sum) {

	if (sum == 0)
		return 1;
	if (n == 0) {
		return 0;
	}

	if (t[sum][n] != -1 ) return t[sum][n];

	if (v[n - 1] <= sum)
		t[sum][n] = subSetSum(v, n - 1, sum - v[n - 1]) + subSetSum(v, n - 1, sum);
	else
		t[sum][n] = subSetSum(v, n - 1, sum);
	return t[sum][n];
}

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int v[] = { 1, 2, 3, 3};
	int sum = 6;
	int n = sizeof(v) / sizeof(v[0]);
	memset(t, -1, sizeof(t));
	rep(i, 101) {
		t[i][0] = 0;
		t[0][i] = 1;
	}
	int count = subSetSum(v, n, sum);
	vector<int> res;
	printSubsetSum(v, n, sum, res);

	printf("count of subsets: %d\n", count);

	return 0;
}

a