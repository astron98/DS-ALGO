#include<bits/stdc++.h>

using namespace std;

void permute(string str, int l, int r) {
	if(l == r) 
		cout << str << " ";
	else {
		for(int i=l;i<=r;i++) {
			swap(str[i],str[l]);
			
			sort(str.begin() + (i+1),str.end());
			permute(str,l+1,r);
			
			swap(str[i],str[l]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str = "abc";
	int n = str.size();
	permute(str,0,n-1);
	cout << "\n";
	return 0;
}
