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

int partition(int *v, int start, int end) {
	//pIndex  = partitionIndex
	int pivot = v[end];
	int pIndex = start;

	for (int i = start; i < end; i++) {
		if (v[i] <= pivot)
		{
			swap(v[i], v[pIndex]);
			pIndex++;
		}
	}
	swap(v[end], v[pIndex]);
	return pIndex;
}

void quickSort(int *v, int start, int end) {
	int pIndex ;
	if (start < end) {
		pIndex = partition(v, start, end);
		quickSort(v, start, pIndex - 1);
		quickSort(v, pIndex + 1, end);
	}
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

	int t = 1, n;
	// cin>>t;
	while (t--) {
		// cin >> n;
		int v[] = {7, 3, 5, 2, 4, 1, 8, 6};
		int n = sizeof(v) / sizeof(v[0]);
		quickSort(v, 0, n - 1);
		cout << "Sorted numbers: ";
		rep(i, n)
		cout << v[i] << " ";

		cout << '\n';
	}
	return 0;
}
