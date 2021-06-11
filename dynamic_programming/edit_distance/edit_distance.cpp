// A Dynamic Programming (NLP) edit-distance.
#include <bits/stdc++.h>
using namespace std;

// Utility function to find the minimum of three numbers
int min(int x, int y, int z)
{
	return min(min(x, y), z);
}


int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems

	// Fill d[][] in bottom up manner
	int x = 0, y = 0, z = 0;
	int dp[m + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n + 1; i++) {
		dp[0][i] = i;
		dp[i][0] = i;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			// if (i == 0)
			// 	dp[i][j] = j; // Min. operations = j

			// // If second string is empty, only option is to
			// // remove all characters of second string
			// else if (j == 0)
			// 	dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string

			x = dp[i - 1][j] + 1;
			y = dp[i][j - 1] + 1;
			z = dp[i - 1][j - 1];

			if (str1[i - 1] != str2[j - 1])
				z = z + 2;

			dp[i][j] = min(x, y, z);
		}
	}

	for (int i = str1.length(); i >= 0; i--) {
		for (int j = 0; j < str2.length() + 1; j++) {
			cout << dp[i][j] << "  ";
		}
		cout << "\n";
	}

	return dp[m][n];
}

// Driver program
int main()
{
	// your code goes here
	string str1 = "intention";	//just give the required inputs here word 1
	string str2 = "execution";  //just give the required inputs here word 2

	cout << editDistDP(str1, str2, str1.length(), str2.length());

	return 0;
}


/*
testcases:
1.
inputs:
intention
execution

2.

heart
start
*/
