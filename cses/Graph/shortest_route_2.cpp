#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,q;
const int mxN = 5e2;
const ll INF = 5e11 + 1;
ll dist[mxN][mxN];

void floyd_warshell(){
	for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main(){
	cin>>n>>m>>q;
	memset(dist,INF,sizeof(dist));
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a, --b;
		if(c < dist[a][b]){
			dist[a][b] = c;
			dist[b][a] = c;
		}
	}
	for(int i=0;i<n;i++)
		dist[i][i] = 0;
	floyd_warshell();
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		if(dist[a][b] >= INF)
			cout<<-1<<endl;
		else
			cout<<dist[a][b]<<endl;
	}
	return 0;
}