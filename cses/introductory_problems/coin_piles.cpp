#include<iostream>
#define ll long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;
		ll minimum, maximum;
		minimum = (a <= b)? a : b;
		maximum = a ^ b ^ minimum;
		ll temp = 2 * minimum - maximum;
		if(temp == 0)
			cout<<"YES"<<endl;
		else if(temp < 0)
			cout<<"NO"<<endl;
		else{
			if(temp % 3 == 0){
				ll n = temp / 3;
				if((minimum - (2*n)) > 0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}