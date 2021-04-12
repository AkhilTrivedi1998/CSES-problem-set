#include<iostream>
#include<set>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n] = {0};
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	cout<<s.size()<<endl;
	return 0;
}