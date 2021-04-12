#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n] = {0};
	stack<pair<int,int>> s;
	vector<int> v;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		while(!s.empty() && s.top().first >= a[i])
			s.pop();
		if(s.empty()){
			if(i == n-1)
				cout<<0<<endl;
			else
				cout<<0<<" ";
		}
		else{
			if(i == n-1)
				cout<<s.top().second<<endl;
			else
				cout<<s.top().second<<" ";
		}
		s.push(make_pair(a[i],i+1));
	}
	return 0;
}