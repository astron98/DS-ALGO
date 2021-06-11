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
vector<int> temp;

void merge(int *v, int start, int mid, int end) {
	int l_index = start;
	int r_index = mid + 1;
	int temp_index = start;

	while (l_index <= mid && r_index <= end) {
		if (v[l_index] <= v[r_index])
			temp[temp_index++] = v[l_index++];
		else
			temp[temp_index++] = v[r_index++];
	}

	//but still some unpicked nos in the left/right part.
	if (l_index <= mid) {
		for (int i = l_index; i <= mid; i++)
			temp[temp_index++] = v[i];
	}
	else  if (r_index <= end) {
		for (int i = r_index; i <= end; i++)
			temp[temp_index++] = v[i];
	}

	for (int i = start; i <= end; i++)	//merging the sorted array
		v[i] = temp[i];
}

void mergeSort(int *v, int start, int end) {


	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(v, start, mid);
		mergeSort(v, mid + 1, end);
		merge(v, start, mid, end);
	}
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int t = 1, n;
	// cin >> t;
	while (t--) {
		// cin>>n;
		// vector<int> v(n);
		// rep(i,n) cin>>v[i];
		int v[] = {7, 3, 5, 2, 4, 1, 8, 6};
		int n = sizeof v / sizeof(v[0]);
		temp.resize(n);	//resizing the temporary array.

		mergeSort(v, 0, n - 1);
		cout << "Sorted numbers: ";
		rep(i, n)
		cout << v[i] << " ";

		cout << '\n';
	}
	return 0;
}
