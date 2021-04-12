#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int t = 1;
	for(int i=0;i<n;i++)
		t = (2*t)%((int)1e9+7);
	cout<<t<<endl;
	return 0;
}