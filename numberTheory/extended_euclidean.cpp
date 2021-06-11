#include<bits/stdc++.h>

int extendedgcd(int a,int b,int *x,int *y) {
	if(a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1,y1;
	int gcd = extendedgcd(b%a,a,&x1,&y1);
	
	*x = y1 - floor(b/a)*x1;
	*y = y1;
	return gcd;
}

using namespace std;

int main() {
	int x, y, a = 35, b = 15;
	int g = extendedgcd(a,b,&x,&y);
	cout << "x and y values for ax + by = gcd(a,b) is x=" << x << ", y="<<y<<" gcd="<<g<<"\n";
	return 0;
}
