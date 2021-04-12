#include<iostream>
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	ll a[n] = {0}, m = 0, s = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] > m)
			m = a[i];
		s += a[i];
	}
	cout<<max(s,2*m)<<endl;
	return 0;
}