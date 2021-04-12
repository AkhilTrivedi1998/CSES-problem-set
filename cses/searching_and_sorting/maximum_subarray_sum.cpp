#include<iostream>
#define ll long long
using namespace std;

const ll nxM = -2e14;

int main(){
	int n;
	cin>>n;
	ll a[n] = {0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll s = 0, max_sum = nxM;
	for(int i=0;i<n;i++){
		s = s + a[i];
		if(s > max_sum)
			max_sum = s;
		if(s < 0)
			s = 0;
	}
	cout<<max_sum<<endl;
	return 0;
}