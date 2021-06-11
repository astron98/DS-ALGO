//  public static ArrayList<String> getStairPaths(int n) {
//         return null;
//     }

#include<bits/stdc++.h>
using namespace std;

vector<string> getStairPaths(int n, string temp) {
    vector<string> rop;
    if (n == 0) {
        return {temp};
    }

    // vector<string>
    for (int i = 1; i < 4; i++) {
        if (n >= i) {
            vector<string> v;
            v = getStairPaths(n - i, temp + to_string(i));

            rop.insert(rop.end(), v.begin(), v.end());
        }
    }
    return rop;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> res = getStairPaths(n, "");
    cout << "[";
    int i = 0;
    for (i = 0; i < res.size() - 1; i++) {
        cout << res[i] << ", ";
    }
    cout << res[i] << "]\n";
    return 0;
}