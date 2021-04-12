#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define arr array
using namespace std;
int main(){
	int n;
	cin>>n;
	set<pair<int, int>> s;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		s.insert(make_pair(2*a, 1));
		s.insert(make_pair(2*b+1, -1));
	}
	int ans = 0, c = 0;
	for(pair<int,int> p : s){
		c += p.second;
		if(c > ans)
			ans = c;
	}
	cout<<ans<<endl;
	return 0;
}