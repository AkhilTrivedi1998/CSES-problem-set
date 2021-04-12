#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	int n;
	ll x;
	cin>>n>>x;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int i = 0, j = n-1, cnt = 0;
	while(i < j){
		if(a[i] + a[j] <= x){
			i++; j--;
		}
		else
			j--;
		cnt++;
	}
	if(i == j)
		cnt++;
	cout<<cnt<<endl;
	return 0;
}