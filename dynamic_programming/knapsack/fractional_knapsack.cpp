// Created by ... astron98

// Fractional knapsack
// hint: DP isn't required here.

#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define mn INT_MIN;
#define mx INT_MAX;

using namespace std;
using ll = long long;

struct Item
{
	int value=0, weight=0;
};

bool compare(struct Item a, struct Item b) {
	double r1 = (double) a.value / a.weight;
	double r2 = (double) b.value / b.weight;

	return r1 > r2;
}

double fractionalKS(int w, struct Item arr[], int n) {
	sort(arr, arr + n, compare);

	int currWeight = 0;
	double result = 0.0;

	rep(i,n) {
		if(currWeight + arr[i].weight <= w) {
			currWeight += arr[i].weight;
			result += arr[i].value;
		}		
		else {
			int remainingWeight = w - currWeight;
			result += (arr[i].value / (double)arr[i].weight) * remainingWeight;
			break;
		}
	}

	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
   	int w,n;
   	cin >> w;
   	cin >> n;
   	struct Item arr[n] = {{ 60, 10 }, { 100, 20 }, { 120, 30 }};
   	string temp = "";
   	// for(int index=0; Index<n; Index++) {
   	// 	// cin >> temp;
   	// 	getline(cin, temp);
   	// 	// ss << temp;
   	// 	stringstream ss(temp);
   	// 	int a[2];
   	// 	int j=0;
   	// 	temp = "";
   	// 	while(getline(ss,temp,' ')) {
   	// 		a[j] = stoi(temp);
   	// 		j++; 
   	// 	}

   	// 	Item[Index].value = a[0];
   	// 	Item[Index].weight = a[1];
   	// 	// ss.clear();
   	// 	temp = "";
   	// }

   	int res = fractionalKS(w, arr, n);

   	cout << res << "\n";

    return 0;
}


/*
testcases:
case 1:
input:
50
3
60 10
100 20
120 30

output:

--------------------
*/