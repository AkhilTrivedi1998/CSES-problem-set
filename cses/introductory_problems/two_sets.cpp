#include<iostream>
#include<list>
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	ll s = ((ll)n * (ll)(n+1))/2;
	if(s%2 == 0){
		cout<<"YES"<<endl;
		int cnt = 0;
		list<int> v1, v2;
		ll s1 = s/2, s2 = 0;
		for(int i=n;i>0;i--){
			if(s2 == s1){
				v2.push_front(i);
			}
			else if(s2 < s1){
				if(s2 + i <= s1){
					cnt++;
					s2 = s2 + i;
					v1.push_front(i);
				}
				else
					v2.push_front(i);
			}
		}
		cout<<cnt<<endl;
		for(auto i=v1.begin(); i != v1.end(); i++)
			cout<<(*i)<<" ";
		cout<<endl;
		cout<<(n - cnt)<<endl;
		for(auto i=v2.begin(); i != v2.end(); i++)
			cout<<(*i)<<" ";
		cout<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}