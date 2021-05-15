#include<iostream>
#include<vector>
#include<set>
#define ll long long
using namespace std;

const ll inf = 1e18;
const int mxN = 1e5;
int n,m;
vector<pair<ll,pair<int,int>>> edge;
// vector<pair<ll,int>> adj1[mxN], adj2[mxN];
// bool vis1[mxN], vis2[mxN];
// ll dis1[mxN], dis2[mxN];

void dijikstra(vector<pair<ll,int>> *adj, bool * vis, ll * dis, int x){
	set<pair<ll,int>> st;
	st.insert(make_pair(0,x));
	dis[x] = 0;
	vis[x] = 1;
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
}

int main(){
	cin>>n>>m;
	vector<pair<ll,int>> adj1[mxN], adj2[mxN];
	bool vis1[mxN], vis2[mxN];
	ll dis1[mxN], dis2[mxN];
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		edge.push_back(make_pair(c,make_pair(a,b)));
		adj1[a].push_back(make_pair(c,b));
		adj2[b].push_back(make_pair(c,a));
	}
	dijikstra(adj1,vis1,dis1,0);
	dijikstra(adj2,vis2,dis2,n-1);
	ll min_d = inf;
	int n1 = edge.size();
	for(int i=0;i<n1;i++){
		ll w = edge[i].first / 2;
		int u = edge[i].second.first, v = edge[i].second.second;
		ll d = dis1[u] + w + dis2[v];
		if(d < min_d)
			min_d = d;
	}
	cout<<min_d<<endl;
	return 0;
}