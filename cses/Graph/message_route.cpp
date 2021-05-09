#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

const int mxN = 1e5;
vector<int> adj[mxN];
bool vis[mxN];
int parent[mxN] = {-1};

void bfs(int n){
	int f = 0;
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	while(!q.empty()){
		int i = q.front();
		int m = adj[i].size();
		for(int j=0;j<m;j++){
			int node = adj[i][j];
			if(!vis[node]){
				vis[node] = 1;
				parent[node] = i;
				if(node == n-1){
					f = 1;
					break;
				}
				q.push(node);
			}
		}
		q.pop();
	}
	if(f == 0)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		list<int> path;
		path.push_front(n);
		int temp = n-1;
		while(temp != 0){
			temp = parent[temp];
			path.push_front(temp+1);
		}
		cout<<path.size()<<endl;
		for(auto itr=path.begin();itr!=path.end();itr++){
			cout<<(*itr)<<" ";
		}
		cout<<endl;
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
	bfs(n);
	return 0;
}