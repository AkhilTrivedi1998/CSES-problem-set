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
int indegree[mxN], outdegree[mxN], cnt = 0;

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
		dfs(ev[e]);
	}
	st.push(i);
}

int main(){
	cin>>n>>m;
	fill(indegree,indegree+n,0);
	fill(outdegree,outdegree+n,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		eu[i] = a;
		ev[i] = b;
		adj[a].pb(i);
		//adj[b].pb(i);
		outdegree[a]++;
		indegree[b]++;
	}
	int f = 0;
	for(int i=0;i<n;i++){
		if(indegree[i] != outdegree[i] && i != 0 && i != n-1){
			f = 1;
			break;
		}
	}
	if(outdegree[0] != indegree[0]+1 || indegree[n-1] != outdegree[n-1]+1)
		f = 1;
	if(f == 1){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		dfs(0);
		int fl = 0;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				if(outdegree[i] != 0 || indegree[i] != 0){
					fl = 1;
					break;
				}
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