#include<iostream>
#include<vector>
using namespace std;

const int mxN = 1e5;
vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int m){
	int n = adj[m].size();
	for(int i=0;i<n;i++){
		if(!vis[adj[m][i]]){
			vis[adj[m][i]] = 1;
			dfs(adj[m][i]);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		--a , --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i] = 1;
			ans.push_back(i);
			dfs(i);
		}
	}
	int res = ans.size()-1;
	cout<<res<<endl;
	if(res >= 1){
		for(int i=1;i<=res;i++){
			cout<<ans[0]+1<<" "<<ans[i]+1<<endl;
		}
	}
	return 0;
}