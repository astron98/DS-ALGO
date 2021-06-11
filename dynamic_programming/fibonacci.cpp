#include<bits/stdc++.h>
using namespace std;

int fib(int n, int *t) {
    if (t[n] != -1)
        return t[n];

    if (n == 0 || n == 1)
        return n;

    t[n] = fib(n - 2, t) +  fib(n - 1, t);

    return t[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int *t = new int[n + 1];
    t[0] = 0, t[1] = 1;
    for (int i = 2; i <= n; i++)
        t[i] = -1;

    int result = fib(n, t);

    printf("%d\n", result);
    return 0;
}