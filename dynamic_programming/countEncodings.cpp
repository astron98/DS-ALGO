// Created by ... astron98
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str="";

    getline(cin,str);

    // countEncoding(str);78
    int n = str.size();
    int t[n];
    memset(t,0,sizeof(t));
    t[0] = 1;
    if(str[0]=='0') {
    	t[n-1]=0;
    }
    string temp = "";
    for (int i = 1; i < n && str[0]!='0'; ++i)
    {
    	temp="";
    	temp = str.substr(i-1,2);
    	char x = stoi(temp) - 1 + 'a';
    	// string x = (string)cc;
    	if(str[i-1]!='0' && x>='a' && x<='z'){
    		t[i] += (i-2 >= 0)? t[i-2]:1;
    	}

    	temp = str[i];
    	x = stoi(temp)-1+'a';
    	// x = cc;
    	if(x>='a' && x<='z'){
    		t[i] += (i-1 >= 0)? t[i-1]:1;
    	}

    	if(t[i]==0) {
    		t[n-1] = 0;
    		break;
    	}
    }

    printf("%d\n", t[n-1]);
    return 0;
}