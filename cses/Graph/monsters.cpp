#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int a[mxN][mxN],mons[mxN][mxN], n, m;
char parent[mxN][mxN];
pair<int,int> str;
vector<pair<int,int>> pos;

bool check_mons(int i,int j){
	return i>=0 && i<n && j>=0 && j<m && mons[i][j] != -2;
}

// void mons_queue_push(queue<pair<int,int>> &q, int d, int i, int j){
// 	if(d >= 2){
// 		if(check_mons(i+1,j)){
// 			if(mons[i+1][j] == -4)
// 				return;
// 		}
// 		if(check_mons(i-1,j)){
// 			if(mons[i-1][j] == -4)
// 				return;
// 		}
// 		if(check_mons(i,j+1)){
// 			if(mons[i][j+1] == -4)
// 				return;
// 		}
// 		if(check_mons(i,j-1)){
// 			if(mons[i][j-1] == -4)
// 				return;
// 		}
// 	}
// 	if(mons[i][j] < 0){
// 		if(mons[i][j] != -4){
// 			mons[i][j] = d;
// 			q.push(make_pair(i,j));
// 		}
// 	}
// 	else{
// 		if(d < mons[i][j]){
// 			mons[i][j] = d;
// 			q.push(make_pair(i,j));
// 		}
// 	}
// }

void mons_queue_push(queue<pair<int,int>> &q, int d, int i, int j){
	if(mons[i][j] < 0){
		if(mons[i][j] != -4){
			mons[i][j] = d;
			q.push(make_pair(i,j));
		}
		else{
			mons[i][j] = 0;
			q.push(make_pair(i,j));
		}
	}
	else{
		if(d < mons[i][j]){
			mons[i][j] = d;
			q.push(make_pair(i,j));
		}
	}
}

void person_queue_push(queue<pair<int,int>> &q, int d, int i, int j){
	if(mons[i][j] < 0 || d < mons[i][j]){
		mons[i][j] = d;
		q.push(make_pair(i,j));
	}
}

void mons_bfs(int k){
	int i1 = pos[k].first, j1 = pos[k].second;
	mons[i1][j1] = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(i1,j1));
	while(!q.empty()){
		pair<int,int> val = q.front();
		q.pop();
		int i = val.first, j = val.second, d = mons[i][j] + 1;
		if(check_mons(i+1,j)){
			mons_queue_push(q,d,i+1,j);
		}
		if(check_mons(i-1,j)){
			mons_queue_push(q,d,i-1,j);
		}
		if(check_mons(i,j+1)){
			mons_queue_push(q,d,i,j+1);
		}
		if(check_mons(i,j-1)){
			mons_queue_push(q,d,i,j-1);
		}
	}
}

bool check_boundary(int i, int j){
	return i==0 || j==0 || i==n-1 || j==m-1;
}

void bfs(){
	int i1 = str.first, j1 = str.second;
	queue<pair<int,int>> q;
	q.push(make_pair(i1,j1));
	mons[i1][j1] = 0;
	int bi = -1, bj = -1;
	while(!q.empty()){
		pair<int,int> val = q.front();
		q.pop();
		int i = val.first, j = val.second;
		int d = mons[i][j] + 1;
		if(check_boundary(i,j)){
			bi = i;
			bj = j;
			break;
		}
		int s1 = q.size(),s2;
		if(check_mons(i+1,j)){
			person_queue_push(q,d,i+1,j);
			s2 = q.size();
			if(s1 < s2){
				parent[i+1][j] = 'D';
				s1 = s2;
				if(check_boundary(i+1,j)){
					bi = i+1;
					bj = j;
					break;
				}
			}
		}
		if(check_mons(i-1,j)){
			person_queue_push(q,d,i-1,j);
			s2 = q.size();
			if(s1 < s2){
				parent[i-1][j] = 'U';
				s1 = s2;
				if(check_boundary(i-1,j)){
					bi = i-1;
					bj = j;
					break;
				}
			}
		}
		if(check_mons(i,j+1)){
			person_queue_push(q,d,i,j+1);
			s2 = q.size();
			if(s1 < s2){
				parent[i][j+1] = 'R';
				s1 = s2;
				if(check_boundary(i,j+1)){
					bi = i;
					bj = j+1;
					break;
				}
			}
		}
		if(check_mons(i,j-1)){
			person_queue_push(q,d,i,j-1);
			s2 = q.size();
			if(s1 < s2){
				parent[i][j-1] = 'L';
				s1 = s2;
				if(check_boundary(i,j-1)){
					bi = i;
					bj = j-1;
					break;
				}
			}
		}
	}
	if(bi == -1)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<mons[bi][bj]<<endl;
		string s = "";
		while(bi != i1 || bj != j1){
			char ch = parent[bi][bj];
			s += ch;
			if(ch == 'D'){
				bi = bi-1;
			}
			else if(ch == 'U'){
				bi = bi+1;
			}
			else if(ch == 'R'){
				bj = bj-1;
			}
			else if(ch == 'L'){
				bj = bj+1;
			}
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			cin>>ch;
			if(ch == '.'){
				//a[i][j] = -1;
				mons[i][j] = -1;
			}
			else if(ch == '#'){
				//a[i][j] = -2;
				mons[i][j] = -2;
			}
			else if(ch == 'A'){
				str = make_pair(i,j);
				//a[i][j] = -3;
				mons[i][j] = -3;
			}
			else if(ch == 'M'){
				pos.push_back(make_pair(i,j));
				//a[i][j] = -4;
				mons[i][j] = -4;
			}
		}
	}
	int m1 = pos.size();
	if(m1 > 0)
		mons_bfs(0);
	bfs();
	return 0;
}