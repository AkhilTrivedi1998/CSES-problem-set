#include<iostream>
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	ll s = 0;
	int p[20];
	for(int i=0;i<n;i++){
		cin>>p[i];
		s += p[i];
	}
	ll ans = 0;
	for(int i=0;i<(1<<n);i++){
		ll cs = 0;
		for(int j=0;j<n;j++){
			if(i>>j & 1)
				cs += p[j];
		}
		if(cs <= s/2)
			ans = max(ans,cs);
	}
	cout<<s - 2*ans<<endl;
	return 0;
}