#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2500;
int n,m;
int parent[mxN], resp = -1;
ll dist[mxN];
bool vis[mxN];
const ll INF = 1e9 + 1;
vector<int> adj[mxN];
vector<pair<ll,pair<int,int>>> edges;

void dfs(int i){
	cout<<i<<endl;
	int n1 = adj[i].size();
	for(int j=0;j<n1;j++){
		if(resp != -1)
			break;
		int node = adj[i][j];
		parent[node] = i;
		if(vis[node]){
			resp = node;
			break;
		}
		else{
			vis[node] = 1;
			dfs(node);
		}
	}
}

int main(){
	cin>>n>>m;
	memset(parent,-1,sizeof(parent));
	memset(dist, INF, sizeof(dist));
	// cout<<"\n\n\n";
	for(int i=0;i<m;i++){
		int a, b;
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		edges.push_back(make_pair(c,make_pair(a,b)));
		// if(a == 22 && b == 2){
		// 	cout<<a<<" "<<b<<" "<<c<<endl;
		// }
		// else if(a == 13 && b == 22){
		// 	cout<<a<<" "<<b<<" "<<c<<endl;
		// }
		// else if(a == 5 && b == 13){
		// 	cout<<a<<" "<<b<<" "<<c<<endl;
		// }
		// else if(a == 17 && b == 5){
		// 	cout<<a<<" "<<b<<" "<<c<<endl;
		// }
		// else if(a == 22 && b == 17){
		// 	cout<<a<<" "<<b<<" "<<c<<endl;
		// }
		//parent[b].push_back(a);
		//adj[b].push_back(a);
	}
	dist[0] = 0;
	int s = edges.size();
	int f = -1;
	for(int i=0;i<n;i++){
		f = -1;
		//cout<<"\n";
		for(int j=0;j<s;j++){
			int u = edges[j].second.first, v = edges[j].second.second;
			ll d = edges[j].first;
			if(dist[u] != INF && dist[v] > dist[u] + d){
				dist[v] = dist[u] + d;
				//cout<<v<<" -- "<<u<<endl;
				parent[v] = u;
				f = v;
			}
		}
	}
	// int f = -1;
	// for(int j=0;j<s;j++){
	// 	int u = edges[j].second.first, v = edges[j].second.second;
	// 	ll d = edges[j].first;
	// 	if(dist[u] != INF && dist[v] > dist[u] + d){
	// 		dist[v] = dist[u] + d;
	// 		parent[v] = u;
	// 		f = v;
	// 	}
	// }
	if(f != -1){
		// vis[f] = 1;
		// dfs(f);
		// int f = resp;
		// cout<<"f = "<<f<<endl;
		cout<<"YES"<<endl;
		// for(int i=0;i<n;i++){
		// 	cout<<" -"<<i+1<<"- "<<parent[i+1]<<endl;
		// }
		// cout<<endl;
		vis[f] = 1;
		// cout<<f<<" ";
		for(int i=0;i<n;i++){
			// cout<<parent[f]<<" ";
			f = parent[f];
			if(vis[f] == 1)
				break;
			else
				vis[f] = 1;
		}
		// cout<<endl;
		// cout<<f<<endl;
		vector<int> cycle;
		int C = f, n1;
		//cout<<C<<endl;
		while(1){
			n1 = cycle.size();
			if(n1 > 0 && C == f){
				cycle.push_back(C);
				break;
			}
			cycle.push_back(C);
			//cout<<C<<endl;
			C = parent[C];
		}
		n1 = cycle.size();
		reverse(cycle.begin(),cycle.end());
		for(int i=0;i<n1;i++)
			cout<<cycle[i]+1<<" ";
		cout<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}