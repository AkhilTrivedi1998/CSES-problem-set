#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
ll power_func(int x, int y){
	if(y == 0)
		return (ll)1;
	if(y == 1)
		return (ll)x;
	ll res = 0;
	if(y % 2 == 0){
		res = power_func(x, y/2);
		res = res * res;
	}
	else{
		res = power_func(x, (y-1)/2);
		res = res * res * (ll)x;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int i = 1;
	while(i <= n){
		if(i == 1)
			cout<<0<<endl;
		else if(i == 2)
			cout<<6<<endl;
		else{
			cout<<(power_func(i,4) - (ll)9*power_func(i,2) + (ll)24*(ll)i - (ll)16)/2<<endl;
		}
		i++;
	}
	return 0;
}