#include<iostream>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll power(int y)
{
	ll x = 2;
    ll res = 1; 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
int main(){
	int n;
	cin>>n;
	cout<<power(n)<<endl;
	return 0;
}