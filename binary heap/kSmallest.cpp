/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>

using namespace std;
typedef ll long long;
void tprime(ll n)
{
    int count=0;
    for(ll i=2;i<n;i++)
    {
        
        if(n%i==0)
            count++;
        if(count>1)
            break;
    }
    if(count==1)
        cout<<"YES \n";
    else    
        cout<<"NO \n";
}

int main()
{
    int n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>> a[i]; 
    for(int j=0;j<n;j++)
		tprime(a[j]);

    return 0;
}
