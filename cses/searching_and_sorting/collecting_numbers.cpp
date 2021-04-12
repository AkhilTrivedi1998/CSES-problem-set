#include<iostream>
using namespace std;

const int nxM = 2e5;

int main(){
	int n;
	cin>>n;
	int a[nxM + 1] = {0};
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		a[temp] = i;
	}
	int cnt = 1,val = 0;
	for(int i=1;i<=n;i++){
		if(a[i] < val)
			cnt++;
		val = a[i];
	}
	cout<<cnt<<endl;
	return 0;
}