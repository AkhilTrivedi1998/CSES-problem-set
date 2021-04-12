#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<pair<int, pair<int, int>>> s;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		s.insert(make_pair(2*a, make_pair(1,i)));
		s.insert(make_pair(2*b+1, make_pair(-1,i)));
	}
	int cnt = 0, max_cnt = 0, f = 1;
	unordered_map<int,int> mp;
	vector<int> v(1, 1);
	for(auto it=s.begin();it != s.end();++it){
		cnt += (*it).second.first;
		if(cnt > max_cnt)
			max_cnt = cnt;
		if((*it).second.first == 1){
			if(v.size() == 0){
				f++;
				v.push_back(f);
			}
			mp[(*it).second.second] = v[0];
			v.erase(v.begin());
		}
		else{
			v.push_back(mp[(*it).second.second]);
		}
	}
	// unordered_map<int,int> mp;
	// vector<int> v(max_cnt, 0);
	// for(int i=0;i<max_cnt;i++)
	// 	v[i] = i+1;
	// for(auto it=s.begin();it != s.end();++it){
	// 	if((*it).second.first == 1){
	// 		mp[(*it).second.second] = v[0];
	// 		v.erase(v.begin());
	// 	}
	// 	else{
	// 		v.push_back(mp[(*it).second.second]);
	// 	}
	// }
	cout<<max_cnt<<endl;
	for(int i=0;i<n;i++)
		cout<<mp[i]<<" ";
	cout<<endl;
	return 0;
}