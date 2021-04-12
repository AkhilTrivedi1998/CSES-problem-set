#include<iostream>
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
	ll n, a = 5;
	cin>>n;
	int i = 1, cnt = 0;
	while(a <= n){
		a = power_func(5, i);
		cnt += (n / a);
		i++; 
	}
	cout<<cnt<<endl;
	return 0;
}