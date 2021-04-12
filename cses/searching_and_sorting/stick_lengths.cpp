#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;

ll fun(ll *a, int n, ll m){
	ll s = 0;
	for(int i=0;i<n;i++)
		s += abs(a[i] - m);
	return s;
}

int main(){
	int n;
	cin>>n;
	ll a[n] = {0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n % 2 == 1)
		cout<<fun(a,n,a[(n+1)/2])<<endl;
	else
		cout<<min(fun(a,n,a[n/2]), fun(a,n,a[(n/2)+1]))<<endl;
	return 0;
}