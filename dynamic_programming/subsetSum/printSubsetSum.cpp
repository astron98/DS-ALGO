#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &res) {
    for (int x : res) {
        cout << x << " ";
    }
    printf("\n");
}
void printSubsets(int sum, int n, vector<vector<int>> &t, int a[], vector<int> &res) {
    if (n == 0 && sum != 0 && t[sum][0]) {
        res.push_back(a[n]);
        print(res);
        return ;
    }

    if (n == 0 && sum == 0) {
        print(res);
        return;
    }

    if (t[sum][n - 1]) {
        vector<int> temp = res;
        printSubsets(sum, n - 1, t, a, temp);
    }

    if (sum >= a[n] && t[sum - a[n]][n - 1]) {
        res.push_back(a[n]);
        printSubsets(sum - a[n], n - 1, t, a, res);
    }
}

int f(int n, int sum, int a[], vector<vector<int>> &t) {
    if (n < 0 || sum < 0) {
        t[sum][n] = 0;
        return 0;
    }

    if (t[sum][n] != -1) return t[sum][n];

    if (!sum) {
        t[sum][n] = 1;
        return 1;
    }

    t[sum][n] = f(sum - a[n], n - 1, a, t) + f(sum, n - 1, a, t);
    return t[sum][n];
}

void solve(int a[], int sum, int n) {
    vector<vector<int>> t(sum + 1, vector<int>(n + 1, -1));

    f(sum, n - 1, a, t);
    if (t[sum][n - 1] == 0)
    {
        printf("There are no subsets with sum %d\n", sum);
        return;
    }
    vector<int> res;
    // printSubsets(sum, n - 1, t, a, res);
}

int main() {
//  cout<<"GfG!";
    int a[] = {1, 2, 3, 3};
    int sum = 6;
    solve(a, sum, 4);
    return 0;
}



