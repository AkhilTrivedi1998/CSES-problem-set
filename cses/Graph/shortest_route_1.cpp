#include<iostream>
#include<vector>
#include<set>
#include<stdio.h>
#define ll long long
using namespace std;

const int inf = 1e9 + 1, mxN = 1e5;
int n,m;
vector<pair<ll,int>> adj[mxN];
bool vis[mxN];
ll dis[mxN];

int main(){
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++){
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		adj[a].push_back(make_pair(c,b));
	}
	//memset(vis,0,4*n);
	//memset(dis,inf,8*n);
	set<pair<ll,int>> st;
	st.insert(make_pair(0,0));
	dis[0] = 0;
	vis[0] = 1;
	while(!st.empty()){
		auto itr = st.begin();
		int node = (*itr).second;
		ll d = (*itr).first;
		vis[node] = 2;
		int n1 = adj[node].size();
		for(int i=0;i<n1;i++){
			int node1 = adj[node][i].second;
			ll d1 = adj[node][i].first;
			ll new_dis = d + d1;
			if(vis[node1] == 0){
				vis[node1] = 1;
				dis[node1] = new_dis;
				st.insert(make_pair(dis[node1],node1));
			}
			else if(vis[node1] == 1){
				if(new_dis < dis[node1]){
					st.erase(st.find(make_pair(dis[node1],node1)));
					st.insert(make_pair(new_dis,node1));
					dis[node1] = new_dis;
				}
			}
		}
		st.erase(itr);
	}
	for(int i=0;i<n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	return 0;
}