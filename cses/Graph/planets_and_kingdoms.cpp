#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
#define pb push_back
using namespace std;

int n, m;
const int mxN = 2e5;
vector<int> adj1[mxN], adj2[mxN];
stack<int> st;
bool vis1[mxN], vis2[mxN];
int kingdom[mxN];

void dfs1(int i){
	vis1[i] = 1;
	int n1 = adj1[i].size();
	for(int j=0;j<n1;j++){
		int node = adj1[i][j];
		if(!vis1[node])
			dfs1(node);
	}
	st.push(i);
}

void dfs2(int i, int k){
	vis2[i] = 1;
	kingdom[i] = k;
	int n2 = adj2[i].size();
	for(int j=0;j<n2;j++){
		int node = adj2[i][j];
		if(!vis2[node])
			dfs2(node,k);
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		adj1[a].pb(b);
		adj2[b].pb(a);
	}
	for(int i=0;i<n;i++){
		if(!vis1[i]){
			dfs1(i);
		}
	}
	int k = 0;
	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(!vis2[node]){
			k++;
			dfs2(node,k);
		}
	}
	cout<<k<<endl;
	for(int i=0;i<n;i++)
		cout<<kingdom[i]<<" ";
	cout<<endl;
	return 0;
}