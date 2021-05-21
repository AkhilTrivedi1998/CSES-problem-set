#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

const int mxN = 1e5;
int n,m;
vector<int> adj[mxN];
ll cnt = 0, mod = 1e9 + 7;
ll dp[mxN];

ll dfs(int i){
	if(dp[i] != -1)
		return dp[i];
	int n1 = adj[i].size();
	ll cnt = 0;
	for(int j=0;j<n1;j++){
		int node = adj[i][j];
		cnt = (cnt%mod + dfs(node)%mod)%mod;
	}
	dp[i] = cnt;
	return cnt;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
	}
	fill(dp,dp+n,-1);
	dp[n-1] = 1;
	cout<<dfs(0)<<endl;
	return 0;
}