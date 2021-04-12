#include<iostream>
#include<set>
#define ll long long
using namespace std;
int main(){
	int n,t;
	cin>>n>>t;
	multiset<pair<ll,ll>> s;
	for(int i=0;i<n;i++){
		ll temp;
		cin>>temp;
		s.insert(make_pair(temp,temp));
	}
	for(int i=0;i<t-1;i++){
		auto it = s.begin();
		ll t1 = it->first, t2 = it->second;
		//cout<<t1<<" "<<t2<<endl;
		s.erase(it);
		s.insert(make_pair(t1+t2,t2));
	}
	auto it = s.begin();
	cout<<it->first<<endl;
	return 0;
}