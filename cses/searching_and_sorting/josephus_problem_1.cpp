#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

typedef tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 


int main(){
	int n,k = 1;
	cin>>n;
	ordered_set s;
	for(int i=1;i<=n;i++)
		s.insert(i);
	int it = 0;
	vector<int> ord;
	while(s.size() > 0){
		int i = s.size();
		int m = i;
		i = (k >= i) ? (k % i) : k;
		it = (it + i) % m;
		ord.push_back(*s.find_by_order(it));
		s.erase(*s.find_by_order(it));
		if(it == m-1)
			it = 0;
	}
	for(int i=0;i<n;i++){
		if(i < n-1)
			cout<<ord[i]<<" ";
		else
			cout<<ord[i]<<endl;
	}
	return 0;
}