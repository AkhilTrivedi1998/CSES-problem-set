#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

#define ar array

using namespace __gnu_pbds; 
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

/*
	We need to use multiset here beacause elements might repeat.
	To simulate multiset in policy based data structure we use pair with second element of pair being the unique index value of the element.
*/
typedef tree<pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

bool cmp(ar<int,3> a,ar<int,3> b){
	if(a[0] == b[0]){
		return a[1] >= b[1];
	}
	return a[0] < b[0];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<ar<int,3>> v1(n);
	// unordered_map<pair<int,int>,pair<int,int>,hash_pair> mp;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		// v.push_back(make_pair(a,b));
		v1[i] = {a,b,i};
		//mp.insert(make_pair(make_pair(a,b),make_pair(0,0)));
	}
	sort(v1.begin(),v1.end(),cmp);
	// int k2 = 0;
	// for(auto l : v1){
	// 	cout<<k2<<" --- "<<l[0]<<" "<<l[1]<<endl;
	// 	k2++;
	// }
	ordered_set s1, s2;
	int it1 = 0,it2 = n-1;
	int ans1[n] = {0},ans2[n] = {0}; 
	int i = 0;
	while(it1 < n && it2 >= 0){
		int x = v1[it1][1] , y = v1[it2][1];
		s1.insert(make_pair(x, n-i));
		int idx1 = s1.order_of_key(make_pair(x,n-i)), sz1 = s1.size()-1;
		ans2[v1[it1][2]] = sz1 - idx1;
		//cout<<i<<" ######## "<<idx1<<" ####### "<<sz1<<endl;
		// if(mp.find(make_pair((*it1).first,x)) != mp.end())
		// 	mp[make_pair((*it1).first,x)] = make_pair(mp[make_pair((*it1).first,x)].first, sz1 - idx1);
		// else
		// 	mp[make_pair((*it1).first,x)] = make_pair(0, sz1 - idx1);
		s2.insert(make_pair(y,i));
		int idx2 = s2.order_of_key(make_pair(y,i));
		ans1[v1[it2][2]] = idx2;
		// if(mp.find(make_pair((*it2).first,y)) != mp.end())
		// 	mp[make_pair((*it2).first,y)] = make_pair(idx2,mp[make_pair((*it2).first,y)].second);
		// else
		// 	mp[make_pair((*it2).first,y)] = make_pair(idx2, 0);
		i++; it1++; it2--;
	}
	for(int j=0;j<n;j++)
		cout<<ans1[j]<<" ";
	cout<<'\n';
	for(int j=0;j<n;j++)
		cout<<ans2[j]<<" ";
	cout<<'\n';
	// int k = 0;
	// for(auto j : v){
	// 	auto it3 = mp.find(j);
	// 	if(k < n-1)
	// 		cout<<(*it3).second.first<<" ";
	// 	else
	// 		cout<<(*it3).second.first<<'\n';
	// 	k++;
	// }
	// k = 0;
	// for(auto j : v){
	// 	auto it3 = mp.find(j);
	// 	if(k < n-1)
	// 		cout<<(*it3).second.second<<" ";
	// 	else
	// 		cout<<(*it3).second.second<<'\n';
	// 	k++;
	// }
	return 0;
}

