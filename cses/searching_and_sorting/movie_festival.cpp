#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int mxN = 2e5;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> a;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.push_back(make_pair(y,x));
	}
	sort(a.begin(),a.end());
	int ans = 0,l = 0;
	for(int i=0;i<n;i++){
		if(l <= a[i].second){
			ans++;
			l = a[i].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}