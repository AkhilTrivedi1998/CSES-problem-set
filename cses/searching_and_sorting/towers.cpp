#include<iostream>
#include<set>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n] = {0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	multiset<int> s;
	for(int i=0;i<n;i++){
		auto it = s.lower_bound(a[i]);
		if(it != s.end()){
			if((*it) != a[i]){
				s.erase(it);
			}
			else{
				it = s.lower_bound(a[i] + 1);
				if(it != s.end())
					s.erase(it);
			}
		}
		s.insert(a[i]);
	}
	cout<<s.size()<<endl;
	return 0;
}