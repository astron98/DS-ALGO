// Created by astron98
//CoinChange min. count of coins to get a sum:

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
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int size, sum;
	cin >> size;
	
	// db1(n);

	int coins[size];
	rep(i, size) {
		cin >> coins[i];
		// db1(coins[i]);
	}

	cin >> sum;
	
	// db1(target);

	ll arr[size+1][sum+1];	// keep the array type as (long long) coz of integer overflow.

	for(int i = 0; i < size + 1; i++)
        arr[i][0] = 0;
    
    // Initialising first row to INT_MAX (undefined)
    // because a sum cannot be made with zero coins:
    for(int j = 0; j < sum + 1; j++)
        arr[0][j] = INT_MAX;
    
    // Applying the recursive solution:
    for(int i = 1; i < size + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(coins[i - 1] > j)  // cannot pick the highest coin:
                arr[i][j] = arr[i - 1][j];
            else  // choosing the best option:
                arr[i][j] = min(1 + arr[i][j - coins[i - 1]], arr[i - 1][j]);
        }
    }

    int res = arr[size][sum];
	res = (res!= INT_MAX)? res : -1;	// when there is no solution possible. return (-1)
	cout << res << "\n";

	return 0;
}

/*
testcase:
1.
in:
4
9
6
5
1
11

out:
2
-------------
in: sum = 15, coins = {1} #so no solution possible
1
4
15

out:
-1
*/