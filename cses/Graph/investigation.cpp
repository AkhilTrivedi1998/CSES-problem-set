#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;
 
const int mxN = 1e5;
int n,m;
vector<pair<ll,int>> adj[mxN];
ll mod = 1e9 + 7, INF = 1e15;
ll cnt[mxN], dis[mxN], max_nodes[mxN], min_nodes[mxN];
int vis[mxN];  

void dijkstra(int p){
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
	q.push(mk(0,p));
	dis[p] = 0;
	cnt[p] = 1;
	while(!q.empty()){
		auto itr = q.top();
		q.pop();
		int i = itr.ss;
		ll w = itr.ff;
		if(!vis[i]){
			vis[i] = 1;
			int n1 = adj[i].size();
			for(int j=0;j<n1;j++){
				int node = adj[i][j].ss;
				ll w1 = adj[i][j].ff + w;
				if(w1 < dis[node]){
					cnt[node] = cnt[i];
					dis[node] = w1;
					max_nodes[node] = max_nodes[i] + 1;
					min_nodes[node] = min_nodes[i] + 1;
					q.push(mk(w1,node));
				}
				else if(w1 == dis[node]){
					cnt[node] = (cnt[node]%mod + cnt[i]%mod)%mod;
					max_nodes[node] = max(max_nodes[node],max_nodes[i]+1);
					min_nodes[node] = min(min_nodes[node], min_nodes[i]+1);
					q.push(mk(w1,node));
				}
			}
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		adj[a].push_back(mk(c,b));
	}
	for(int i=0;i<100000;i++){
		dis[i] = INF;
		cnt[i] = 0;
		max_nodes[i] = 0;
		min_nodes[i] = 0;
	}
	dijkstra(0);
	cout<<dis[n-1]<<" "<<cnt[n-1]<<" "<<min_nodes[n-1]<<" "<<max_nodes[n-1]<<endl;
	return 0;
}