#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

int n, m;
const int mxN = 2e5;
vector<pair<ll,int>> adj[mxN];
ll dist[mxN], INF = 1e15, res = 0;
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
bool vis[mxN];
int vis_cnt;

void prims(){
	while(!q.empty() && vis_cnt < n){
		auto itr = q.top();
		q.pop();
		int i = itr.ss;
		ll w = itr.ff;
		if(vis[i] == 1)
			continue;
		vis[i] = 1;
		vis_cnt++;
		res += w;
		int n1 = adj[i].size();
		for(int j=0;j<n1;j++){
			auto itr1 = adj[i][j];
			int node = itr1.ss;
			ll weight = itr1.ff;
			if(vis[node] == 1)
				continue;
			if(weight < dist[node]){
				dist[node] = weight;
				q.push(mk(weight,node));
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		adj[a].push_back(mk(c,b));
		adj[b].push_back(mk(c,a));
	}
	for(int i=1;i<n;i++){
		dist[i] = INF;
	}
	dist[0] = 0;
	q.push(mk(0,0));
	prims();
	if(vis_cnt != n)
		cout<<"IMPOSSIBLE"<<endl;
	else
		cout<<res<<endl;
	return 0;
}