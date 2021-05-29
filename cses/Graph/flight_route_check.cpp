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
vector<int> leader;

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

void dfs2(int i){
	vis2[i] = 1;
	int n2 = adj2[i].size();
	for(int j=0;j<n2;j++){
		int node = adj2[i][j];
		if(!vis2[node])
			dfs2(node);
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
	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(!vis2[node]){
			leader.pb(node);
			dfs2(node);
		}
	}
	int l = leader.size();
	if(l == 1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
		cout<<leader[1]+1<<" "<<leader[0]+1<<endl;
	}
	return 0;
}