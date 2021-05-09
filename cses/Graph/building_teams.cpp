#include<iostream>
#include<vector>
using namespace std;

const int mxN = 1e5;
vector<int> adj[mxN];
int color[mxN], f = 0;

void dfs(int n, int clr){
	int m = adj[n].size();
	for(int i=0;i<m;i++){
		if(f == 1)
			break;
		int node = adj[n][i];
		if(!color[node]){
			color[node] = (clr == 1) ? 2 : 1;
			dfs(node,color[node]);
		}
		else{
			if(color[node] == clr){
				f = 1;
				break;
			}
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		if(!color[i]){
			color[i] = 1;
			dfs(i,1);
			if(f == 1)
				break;
		}
	}
	if(f == 1)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		for(int i=0;i<n;i++){
			cout<<color[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}