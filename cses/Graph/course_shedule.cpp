#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

const int mxN = 1e5;
int n,m,f = 0;
vector<int> adj[mxN];
int parent[mxN];
bool vis[mxN], act[mxN];
vector<int> cycle;
stack<int> s;
queue<int> q;

void dfs(int i){
	act[i] = 1;
	vis[i] = 1;
	int n1 = adj[i].size();
	for(int j=0;j<n1;j++){
		if(f == 1)
			return;
		int node = adj[i][j];
		if(!vis[node]){
			dfs(node);
		}
		else{
			if(act[node]){
				f = 1;
				break;
			}
		}
	}
	s.push(i);
	act[i] = 0;
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
		if(f != 0)
			break;
	}
	if(f == 1)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		while(!s.empty()){
			cout<<s.top()+1<<" ";
			s.pop();
		}
		cout<<endl;
	}
	return 0;
}