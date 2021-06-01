#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
#define pb push_back
using namespace std;

int n, m;
const int mxN = 1e5, mxM = 2e5;
vector<int> adj[mxN];
int eu[mxM],ev[mxM];
stack<int> st;
bool used[mxM],vis[mxN];
int degree[mxN], cnt = 0;

void dfs(int i){
	if(!vis[i]){
		vis[i] = 1;
		cnt++;
	}
	while(adj[i].size()){
		int e = adj[i].back();
		adj[i].pop_back();
		if(used[e])
			continue;
		used[e] = 1;
		dfs(eu[e]^ev[e]^i);
	}
	st.push(i);
}

int main(){
	cin>>n>>m;
	fill(degree,degree+n,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		eu[i] = a;
		ev[i] = b;
		adj[a].pb(i);
		adj[b].pb(i);
		degree[a]++;
		degree[b]++;
	}
	int f = 0;
	for(int i=0;i<n;i++){
		if(degree[i]%2 == 1){
			f = 1;
			break;
		}
	}
	if(f == 1){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		dfs(0);
		int fl = 0;
		for(int i=0;i<n;i++){
			if(!vis[i] && degree[i]){
				fl = 1;
				break;
			}
		}
		if(fl == 1)
			cout<<"IMPOSSIBLE"<<endl;
		else{
			while(!st.empty()){
				cout<<st.top()+1<<" ";
				st.pop();
			}
		}
	}
	return 0;
}