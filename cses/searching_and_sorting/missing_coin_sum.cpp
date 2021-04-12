#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

const ll nxM = 2e14;

using namespace std;
int main(){
	int n;
	cin>>n;
	ll a[n] = {0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll res = 1, max_val = -1;
	for(int i=0;i<n;i++){
		if(a[i] <= res)
			res = res + a[i];
		else if(a[i] > res)
			break;
	}
	cout<<res<<endl;
	return 0;
}