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

void permuteUtil(string &str, int count[], string &res, int level, vector<string> &result, int &n) {
	if (level == n) {
		// cout <<res<<" ";
		result.push_back(res);
// 		printf("y ");
		return;
	}

	for (int i = 0; i < str.size(); i++) {
		if (count[i] == 0) continue;

		res[level] = str[i];
		count[i]--;
		permuteUtil(str, count, res, level + 1, result, n);
		count[i]++;

	}
}

void solve(string s) {
	int n = s.size();
	map<char, int> countMap;

	for (char ch : s) {

		if (countMap.find(ch) != countMap.end())
			countMap[ch] += 1;
		else
			countMap[ch] = 1;
		//printf("%d ",countMap[ch]);
	}
// 	printf("\n");

	string str = "";
	int count[n], i = 0;
	for (auto &x : countMap) {
		str += x.first;
		count[i++] = x.second;
	}

	vector<string> result;
	string res = "";
	permuteUtil(str, count, res, 0, result, n);
	for (auto &str : result) {
		cout << str << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1, n;
// 	cin >> t;
// 	cin.ignore();
// 	string s="";
	while (t--) {
		string s = "AABC";
// 		getline(cin, s);
		cout << "input:" << s << "\n";
		solve(s);
	}
	return 0;
}
