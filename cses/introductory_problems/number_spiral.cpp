#include<iostream>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll y,x;
		cin>>y>>x;
		ll maximum = max(y,x);
		if(maximum%2 == 0){
			if(y-x > 0)
				cout<<(maximum-1)*(maximum-1) + y + (y-x)<<endl;
			else
				cout<<(maximum-1)*(maximum-1) + y<<endl;
		}
		else{
			if(x-y > 0)
				cout<<(maximum-1)*(maximum-1) + x + (x-y)<<endl;
			else
				cout<<(maximum-1)*(maximum-1) + x<<endl;
		}
	}
	return 0;
}