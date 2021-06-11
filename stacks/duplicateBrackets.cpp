// Created by astron98
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

bool solver(string &s) {
	stack<char> checkStack;
	int count = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];

		if (c == '(' || c != ')') {
			checkStack.push(c);
		}
		else if (c == ')') {
			count = 0;
			while (!checkStack.empty() && checkStack.top() != '(') {
				checkStack.pop();
				count++;
			}

			if (count > 0 && !checkStack.empty() && checkStack.top() == '(')
				checkStack.pop();
			else
				return true;
		}
	}

	return false;
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
	getline(cin, s);
	// cout << s << endl;

	if (solver(s))
		cout << "true" << "\n";
	else
		cout << "false\n";

	return 0;
}
