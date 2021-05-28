#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

int n, m;
const int mxN = 2e5;
vector<pair<int,int>> edges;
int p[mxN], s[mxN];

int parent(int i){
	if(p[i] == i)
		return i;
	p[i] = parent(p[i]);
	return p[i];
}

void swap(int *s, int *l){
	int temp = (*l);
	(*l) = (*s);
	(*s) = temp;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a, --b;
		edges.push_back(mk(a,b));
	}
	for(int i=0;i<n;i++){
		p[i] = i;
		s[i] = 1;
	}
	int num = n, max_val = 1;
	for(int i=0;i<m;i++){
		int u = edges[i].ff, v = edges[i].ss;
		int pu = parent(u), pv = parent(v);
		if(pu != pv){
			num--;
			if(s[pv] < s[pu])
				swap(&pv, &pu);
			p[pu] = pv;
			s[pv] = s[pu] + s[pv];
			if(s[pv] > max_val)
				max_val = s[pv];
			cout<<num<<" "<<max_val<<endl;
		}
		else{
			cout<<num<<" "<<max_val<<endl;
		}
	}
	return 0;
}