#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// string mp[] = {};
void printEncoding(int i, string s, string ans) {
	int n = s.size();
	if (i >= s.size()) {
		if (i == s.size())
			cout << ans << "\n";
		return;
	}

	string case1 = "", case2 = "";
	bool flag1 = false, flag2 = false;

	char c = '0';
	c = stoi(s.substr(i, 1)) - 1 + 'a';
	case1 = c;

	if (stoi(s.substr(i, 1)) == 0 || case1 < "a" || case1 > "z")
	{
		flag1 = true;
		return;
	}

	if ((i > 0) && i < s.size() - 1) {
		case2 = stoi(s.substr(i, 2)) - 1 + 'a';
		if (stoi(s.substr(i, 2)) == 0 || case2 < "a" || case2 > "z")
			flag2 = true;
	}

	if (!flag1)
		printEncoding(i + 1, s, ans + case1);
	if (!flag2)
		printEncoding(i + 2, s, ans + case2);
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
	printEncoding(0, s, "");

	return 0;
}