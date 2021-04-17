#include<iostream>
#include<map>
#define ll long long
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	ll s = 0;
	map<ll, ll> mp;
	mp[0] = 1;
	ll cnt = 0;
	for(int i=0;i<n;i++){
		ll temp;
		cin>>temp;
		s += temp;
		cnt += mp[s-x];
		mp[s] += 1;
	}
	cout<<cnt<<endl;
	return 0;
}