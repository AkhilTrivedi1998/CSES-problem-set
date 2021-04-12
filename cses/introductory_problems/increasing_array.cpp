#include<iostream>
#define ll long long
using namespace std;
int main(){
	int n;
	ll count = 0;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i] < a[i-1]){
			count += a[i-1] - a[i];
			a[i] = a[i-1];
		}
	}
	cout<<count<<endl;
	return 0;
}