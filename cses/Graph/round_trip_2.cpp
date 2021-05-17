#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

const int mxN = 1e5;
int n,m,f = -1;
vector<int> adj[mxN];
int parent[mxN];
bool vis[mxN], act[mxN];
vector<int> cycle;

void dfs(int i){
	//cout<<"-----"<<i+1<<endl;
	if(f != -1)
		return;
	vis[i] = 1;
	act[i] = 1;
	int n1 = adj[i].size();
	for(int j=0;j<n1;j++){
		if(f != -1)
			return;
		int node = adj[i][j];
		parent[node] = i;
		if(!vis[node])
			dfs(node);
		else{
			if(act[node]){
				f = node;
				break;
			}
		}
	}
	act[i] = 0;
}

void get_cycle(){
	//cout<<"cycle"<<endl;
	cycle.push_back(f);
	int c = f;
	while(1){
		c = parent[c];
		cycle.push_back(c);
		if(c == f)
			break;
	}
	reverse(cycle.begin(),cycle.end());
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
	}
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(i);
		if(f != -1)
			break;
	}
	if(f == -1)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		get_cycle();
		int n1 = cycle.size();
		cout<<n1<<endl;
		for(int i=0;i<n1;i++)
			cout<<cycle[i]+1<<" ";
		cout<<endl;
	}
	return 0;
}