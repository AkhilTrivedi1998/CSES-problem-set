#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<ll>> a(n,vector<ll>(2,0));
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1];
	sort(a.begin(),a.end());
	ll ans = 0, t = 0;
	for(int i=0;i<n;i++){
		t += a[i][0];
		ans += (a[i][1] - t);
	}
	cout<<ans<<endl;
	return 0;
}