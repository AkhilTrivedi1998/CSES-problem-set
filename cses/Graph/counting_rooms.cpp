#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m;
char a[mxN][mxN];

bool f(int i,int j){
	return i>=0 && i<n && j>=0 && j<m && a[i][j] == '.';
}

void dfs(int i,int j){
	a[i][j] = '#';
	if(f(i-1,j))
		dfs(i-1,j);
	if(f(i+1,j))
		dfs(i+1,j);
	if(f(i,j-1))
		dfs(i,j-1);
	if(f(i,j+1))
		dfs(i,j+1);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f(i,j)){
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}