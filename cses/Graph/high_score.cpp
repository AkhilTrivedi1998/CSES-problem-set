#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

const int mxN = 2500;
int n,m;
int parent[mxN];
int vis[mxN], vis1[mxN], vis2[mxN];
const ll INF = 1e15;
vector<ll> dist(mxN,INF);
vector<int> adj1[mxN], adj2[mxN];
vector<pair<ll,pair<int,int>>> edges;

void dfs1(int i){
	vis1[i] = 1;
	for(int j : adj1[i]){
		if(vis1[j] != 1)
			dfs1(j);
	}
}

void dfs2(int i){
	vis2[i] = 1;
	for(int j : adj2[i]){
		if(vis2[j] != 1)
			dfs2(j);
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		ll x;
		cin>>a>>b>>x;
		--a, --b;
		adj1[a].push_back(b);
		adj2[b].push_back(a);
		edges.push_back(make_pair(-1*x,make_pair(a,b)));
	}
	//memset(dist,INF,mxN);
	// for(int i=0;i<n;i++)
	// 	cout<<dist[i]<<endl;
	memset(vis,0,mxN);
	memset(vis1,0,mxN);
	memset(vis2,0,mxN);
	dist[0] = 0;
	//cout<<"------"<<endl;
	for(int i=0;i<n-1;i++){
		for(auto edge : edges){
			int u = edge.ss.ff, v = edge.ss.ss;
			ll w = edge.ff;
			//cout<<u+1<<" "<<v+1<<" "<<dist[v]<<" "<<dist[u]+w<<endl;
			if(dist[u] != INF && dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				//cout<<"        "<<u+1<<" "<<v+1<<" "<<dist[v]<<endl;
				parent[v] = u;
			}
		}
	}
	for(auto edge : edges){
		int u = edge.ss.ff, v = edge.ss.ss;
		ll w = edge.ff;
		if(dist[u] != INF && dist[v] > dist[u] + w){
			vis[v] = 1;
		}
	}
	dfs1(0);
	dfs2(n-1);
	int f = 0;
	for(int i=0;i<n;i++){
		if(vis[i] + vis1[i] + vis2[i] == 3){
			f = 1;
			break;
		}
	}
	if(f == 1)
		cout<<-1<<endl;
	else
		cout<<-1*dist[n-1]<<endl;
	return 0;
}