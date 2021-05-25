#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

int n,q;
const int mxN = 2e5;
int t[mxN];

int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>t[i];
		t[i]--;
	}
	int dp[30][n];
	for(int i=0;i<n;i++)
		dp[0][i] = t[i];
	for(int i=1;i<30;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}
	while(q--){
		int x,k;
		cin>>x>>k;
		x--;
		int i = 0, j = 1;
		while(k != 0){
			if(k & 1){
				x = dp[i][x];
			}
			i++;
			k = k/2;
		}
		cout<<x+1<<endl;
	}
	return 0;
}