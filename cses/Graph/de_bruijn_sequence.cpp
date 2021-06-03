#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
#define pb push_back
using namespace std;

int n, m;
const int mxN = 1e5;
int adj[mxN][2];
stack<char> st;
string ans = "";

void dfs(int i = 0){
	int temp1 = adj[i][0], temp2 = adj[i][1];
	if(adj[i][0] != -1){
		adj[i][0] = -1;
		dfs(temp1);
		st.push('0');
	}
	if(adj[i][1] != -1){
		adj[i][1] = -1;
		dfs(temp2);
		st.push('1');
	}
}

int main(){
	cin>>n;
	if(n == 1){
		cout<<"10"<<endl;
		return 0;
	}
	m = 1<<(n-1);
	for(int i=0;i<m;i++){
		adj[i][0] = (i<<1) & (m-1);
		adj[i][1] = adj[i][0] + 1;
		//cout<<i<<" "<<adj[i][0]<<" "<<adj[i][1]<<endl;
	}
	for(int i=0;i<n-1;i++)
		ans.pb('0');
	dfs();
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	cout<<ans<<endl;
	return 0;
}