#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

const int mxN = 1e5;
int n,m,k;
vector<pair<ll,int>> adj1[mxN];

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		adj1[a].push_back(make_pair(c,b));
	}
	vector<ll> d[n];
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		auto itr = q.top();
		q.pop();
		ll w = itr.ff;
		int node = itr.ss;
		int n1 = d[node].size();
		if(n1 >= k)
			continue;
		d[node].push_back(w);
		n1 = adj1[node].size();
		for(int i=0;i<n1;i++)
			q.push(make_pair(w + adj1[node][i].ff, adj1[node][i].ss));
	}
	for(int i=0;i<k;i++)
		cout<<d[n-1][i]<<" ";
	cout<<endl;
	return 0;
}
