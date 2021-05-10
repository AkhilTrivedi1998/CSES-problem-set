#include<iostream>
#include<vector>
using namespace std;

const int mxN = 1e5;
vector<int> adj[mxN];
bool vis[mxN];
int f = 0, init, fin;
int p[mxN];

void dfs(int i){
	int n = adj[i].size();
	for(int j=0;j<n;j++){
		if(f == 1)
			break;
		int node = adj[i][j];
		//cout<<i<<"  "<<node<<endl;
		if(vis[node] == 1){
			//cout<<"hello"<<endl;
			if(p[i] != node){
				//cout<<"hi"<<endl;
				f = 1;
				init = i;
				fin = node;
				break;
			}
		}
		else{
			//cout<<"bye ";
			vis[node] = 1;
			p[node] = i;
			//cout<<i<<" "<<p[node]<<endl;
			dfs(node);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	//memset(p,-1,4*n);
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i] = 1;
			p[i] = -1;
			dfs(i);
		}
	}
	if(f == 0)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		vector<int> route;
		route.push_back(init);
		int i = 0;
		while(route[i] != fin){
			route.push_back(p[route[i]]);
			i++;
		}
		route.push_back(init);
		int res = route.size();
		cout<<res<<endl;
		for(int i=0;i<res;i++){
			cout<<route[i]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}