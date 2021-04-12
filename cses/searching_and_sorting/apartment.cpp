#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[n] = {0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	int b[m] = {0};
	for(int i=0;i<m;i++)
		cin>>b[i];
	int i = 0, j = 0, cnt = 0;
	sort(a, a+n);
	sort(b, b+m);
	// for(int i=0;i<m;i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	// for(int i=0;i<m;i++)
	// 	cout<<b[i]<<" ";
	// cout<<endl;
	while(i < n && j < m){
		if(b[j] < a[i] - k)
			j++;
		else if(b[j] > a[i] + k)
			i++;
		else{
			// cout<<a[i]<<" - "<<b[j]<<endl;
			i++; j++; cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}