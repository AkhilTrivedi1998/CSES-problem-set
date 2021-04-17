#include<iostream>
#define ll long long
using namespace std;
bool check(ll mid, int *a, int n, int k){
	int cnt = 0;
	ll s = 0;
	for(int i=0;i<n;i++){
		if(a[i] > mid)
			return false;
		s += a[i];
		if(s > mid){
			cnt++;
			s = a[i];
		}
	}
	cnt++;
	if(cnt <= k)
		return true;
	else
		return false;
}

ll binarySearch(int *a, int n, ll l, ll r, int k){
	ll ans = 0;
	while(l <= r){
		ll mid = (l + r)/2;
		if(check(mid,a,n,k)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}	
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	int a[n] = {0};
	ll s = 0, max_ele = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s += a[i];
		if(a[i] > max_ele)
			max_ele = a[i];
	}
	cout<<binarySearch(a,n,max_ele,s,k)<<endl;
	return 0;
}