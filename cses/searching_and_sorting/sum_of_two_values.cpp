#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	int n;
	ll x;
	cin>>n>>x;
	vector<pair<ll, int>> v;
	for(int i=0;i<n;i++){
		ll temp;
		cin>>temp;
		v.push_back(make_pair(temp,i+1));
	}
	sort(v.begin(),v.end());
	int i=0,j=n-1,id1 = -1,id2 = -1;
	while(i < j){
		if(v[i].first + v[j].first == x){
			id1 = min(v[i].second,v[j].second);
			id2 = max(v[i].second, v[j].second);
			break;
		}
		else if(v[i].first + v[j].first < x)
			i++;
		else
			j--;
	}
	if(id1 == -1)
		cout<<"IMPOSSIBLE"<<endl;
	else
		cout<<id1<<" "<<id2<<endl;
	return 0;
}