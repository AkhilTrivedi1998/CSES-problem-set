#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n,m;
//pair<char,int> a[mxN][mxN];
char a[mxN][mxN];
int b[mxN][mxN];

bool check(int i,int j){
	return i>=0 && i<n && j>=0 && j<m && (a[i][j] == '.' || a[i][j] == 'B');
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>m;
	pair<int,int> srt, fin;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			cin>>ch;
			if(ch == 'A'){
				a[i][j] = ch;
				b[i][j] = 0;
			}
			else{
				a[i][j] = ch;
				b[i][j] = -1;
			}
			if(ch == 'A')
				srt = make_pair(i,j);
			if(ch == 'B')
				fin = make_pair(i,j);
		}
	}
	queue<pair<int,int>> v;
	v.push(make_pair(srt.first,srt.second));
	int f = 0;
	while(v.size() != 0){
		pair<int,int> v1 = v.front();
		int i = v1.first, j = v1.second;
		int val = b[i][j];
		//cout<<i<<"  "<<j<<"  -  "<<val<<" ## "<<a[i][j].first<<endl;
		if(i == fin.first && j == fin.second){
			f = 1;
			break;
		}
		if(check(i-1,j)){
			v.push(make_pair(i-1,j));
			a[i-1][j] = 'U';
			b[i-1][j] = val+1;
			if(i-1 == fin.first && j == fin.second){
				f = 1;
				break;
			}
		}
		if(check(i+1,j)){
			v.push(make_pair(i+1,j));
			a[i+1][j] = 'D';
			b[i+1][j] = val+1;
			if(i+1 == fin.first && j == fin.second){
				f = 1;
				break;
			}
		}
		if(check(i,j-1)){
			v.push(make_pair(i,j-1));
			a[i][j-1] = 'L';
			b[i][j-1] = val+1;
			if(i == fin.first && j-1 == fin.second){
				f = 1;
				break;
			}
		}
		if(check(i,j+1)){
			v.push(make_pair(i,j+1));
			a[i][j+1] = 'R';
			b[i][j+1] = val+1;
			if(i == fin.first && j+1 == fin.second){
				f = 1;
				break;
			}
		}
		v.pop();
	}
	if(f == 0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		int i = fin.first, j = fin.second;
		cout<<b[i][j]<<endl;
		string s = "";
		while(i != srt.first || j != srt.second){
			char ch = a[i][j];
			s += ch;
			//cout<<i<<" "<<j<<endl;
			if(ch == 'D'){
				i = i-1;
			}
			if(ch == 'U'){
				i = i+1;
			}
			if(ch == 'R'){
				j = j-1;
			}
			if(ch == 'L'){
				j = j+1;
			}
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	return 0;
}