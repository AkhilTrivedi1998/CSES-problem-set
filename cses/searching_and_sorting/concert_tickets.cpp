#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int binary_search(vector<int> &v, int val, int i, int l){
	if(i > l)
		return -1;
	else{
		int mid = (i+l)/2;
		if(v[mid] < val){
			int temp = binary_search(v, val, mid+1, l);
			if(temp == -1){
				temp = v[mid];
				v.erase(v.begin()+mid);
				return temp;
			}
		}
		else if(v[mid] == val){
			int temp = v[mid];
			v.erase(v.begin()+mid);
			return temp;
		}
		else{
			return binary_search(v,val,i,mid-1);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	set<pair<int, int>> t;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		t.insert(make_pair(temp, i));
	}
	for(int i=0;i<m;i++){
		int h;
		cin>>h;
		auto it = t.lower_bound(make_pair(h+1,0));
		if(it == t.begin())
			cout<<-1<<endl;
		else{
			--it;
			cout<<(*it).first<<endl;
			t.erase(it);
		}
	}
	return 0;
}