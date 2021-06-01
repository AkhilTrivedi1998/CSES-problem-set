#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
#define pb push_back
using namespace std;

int n, m, comp_graph_size;
const int mxN = 1e5;
ll coins[mxN];
vector<int> adj1[mxN], adj2[mxN], comp_graph_adj[mxN];
stack<int> st;
bool vis1[mxN], vis2[mxN], vis3[mxN], vis4[mxN];
int parent[mxN];
ll comp_graph_coins[mxN], dp[mxN], max_val = 0;


void dfs5(int i,ll * val){
	vis3[i] = 1;
	int p1 = parent[i];
	dp[p1] += coins[i];
	int n1 = adj1[i].size();
	for(int j=0;j<n1;j++){
		int node = adj1[i][j];
		int p2 = parent[node];
		if(p1 == p2){
			if(!vis3[node])
				dfs5(node,val);
		}
		else{
			if(!vis3[node]){
				ll k = 0;
				dfs5(node,&k);
				dp[parent[node]] += k;
				if(dp[parent[node]] > *val)
					*val = dp[parent[node]];
			}
			else{
				if(dp[parent[node]] > *val)
					*val = dp[parent[node]];
			}
		}
	}
}

void dfs2(int i, int p){
	//cout<<2<<endl;
	vis2[i] = 1;
	parent[i] = p;
	comp_graph_coins[p] += coins[i];
	int n2 = adj2[i].size();
	for(int j=0;j<n2;j++){
		int node = adj2[i][j];
		if(!vis2[node])
			dfs2(node,p);
	}
}

void dfs1(int i){
	//cout<<1<<endl;
	vis1[i] = 1;
	int n1 = adj1[i].size();
	for(int j=0;j<n1;j++){
		int node = adj1[i][j];
		if(!vis1[node])
			dfs1(node);
	}
	st.push(i);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>coins[i];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		adj1[a].pb(b);
		adj2[b].pb(a);
	}
	for(int i=0;i<n;i++){
		if(!vis1[i])
			dfs1(i);
	}
	int it = 0;
	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(!vis2[node]){
			dfs2(node, it);
			it++;
		}
	}
	for(int i=0;i<n;i++){
		if(!vis3[i]){
			ll val = 0;
			dfs5(i,&val);
			dp[parent[i]] += val;
			if(max_val < dp[parent[i]])
				max_val = dp[parent[i]];
		}
	}
	cout<<max_val<<endl;
	// comp_graph_size = it;
	// fill(comp_graph_coins,comp_graph_coins+it,0);
	// // for(int i=0;i<it;i++){
	// // 	comp_graph_2d[i] = vector<int> (it, 0);
	// // }
	// for(int i=0;i<n;i++){
	// 	if(!vis3[i]){
	// 		dfs3(i);
	// 	}
	// }
	// //cout<<"Hello"<<endl;
	// fill(dp,dp+it,-1);
	// for(int i=0;i<it;i++){
	// 	if(!vis4[i]){
	// 		dfs4(i);
	// 	}
	// }
	// cout<<max_val<<endl;
	// cout<<"----"<<endl;
	// for(int i=0;i<it;i++){
	// 	cout<<comp_graph_coins[i]<<endl;
	// }
	// for(int i=0;i<it;i++){
	// 	cout<<i<<" - ";
	// 	int n1 = comp_graph_adj[i].size();
	// 	for(int j=0;j<n1;j++){
	// 		cout<<comp_graph_adj[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}