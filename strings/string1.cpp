#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
	 int t=0;
	 scanf("%d\n",&t);
	 while(t >0){
	    string str;
	    getline(cin,str);
	    
	    unordered_set<char> chk;
	    string ans;
	    for(int i=0;i<str.size();i++){
	        if(chk.find(str[i])==chk.end()){
	            chk.insert(str[i]);
	            ans+=str[i];
	        }
	    }
	    cout<<t<<": "<<ans<<"\n";
	    
	     t--;
	 }
	 
	return 0;
}
