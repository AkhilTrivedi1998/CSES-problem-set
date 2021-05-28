#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

int n, f;
const int mxN = 2e5;
int t[mxN], cnt[mxN], id[mxN];
bool vis[mxN], active[mxN];

int dfs(int i){
	active[i] = 1;
	vis[i] = 1;
	int node = t[i];
	if(!vis[node]){
		id[node] = id[i] + 1;
		int temp = dfs(node);
		if(f != -1){
			if(id[i] >= f)
				cnt[i] = temp;
			else
				cnt[i] = temp+1;
		}
		else{
			cnt[i] = temp+1;
		}
	}
	else if(vis[node] == 1 && active[node] == 1){
		f = id[node];
		cnt[i] = id[i] - id[node] + 1;
	}
	else if(vis[node] == 1 && active[node] == 0){
		cnt[i] = cnt[node] + 1;
	}
	active[i] = 0;
	return cnt[i];
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i];
		t[i]--;
	}
	fill(cnt,cnt+n,0);
	fill(active,active+n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			f = -1;
			id[i] = 0;
			dfs(i);
		}
	}
	for(int i=0;i<n;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
	return 0;
}