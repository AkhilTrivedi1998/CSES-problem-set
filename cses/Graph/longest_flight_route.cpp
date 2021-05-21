#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

const int mxN = 1e5, INF = 1e6;
int n,m,f = 0;
vector<int> adj[mxN];
bool vis[mxN];
int parent[mxN];
stack<int> s;
int dist[mxN];

void dfs_topological_sort(int i){
	int n1 = adj[i].size();
	for(int j=0;j<n1;j++){
		int node = adj[i][j];
		if(!vis[node]){
			vis[node] = 1;
			dfs_topological_sort(node);
		}
	}
	s.push(i);
}

void topological_sort(){
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs_topological_sort(i);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
	}
	topological_sort();
	fill(dist, dist + n, INF);
	dist[0] = 0;
	while(!s.empty()){
		int u = s.top();
		s.pop();
		int n1 = adj[u].size();
		for(int j=0;j<n1;j++){
			int v = adj[u][j];
			if(dist[u] != INF && dist[u] - 1 < dist[v]){
				dist[v] = dist[u] - 1;
				parent[v] = u;
			}
		}
	}
	if(dist[n-1] == INF){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		vector<int> path;
		int node = n-1;
		while(node != 0){
			path.push_back(node);
			node = parent[node];
		}
		path.push_back(node);
		reverse(path.begin(),path.end());
		cout<<path.size()<<endl;
		for(int i=0;i<path.size();i++){
			cout<<path[i]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}