
// public static void printPermutations(String str) {

// }

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void printPermutations(string s, string rof) {
	if (s.size() == 0) {
		cout << rof << "\n";
		return;
	}

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		string part1 = s.substr(0, i);
		string part2 = s.substr(i + 1);

		printPermutations(part1 + part2, rof + c);
	}
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

	string s;
	cin >> s;

	printPermutations(s, "");
	return 0;
}
