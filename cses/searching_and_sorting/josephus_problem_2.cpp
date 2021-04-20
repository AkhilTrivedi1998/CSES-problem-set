#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

/*
	We could use set here but it gives a time complexity of O(N^2) which in competitions will exceed the time limit
	whereas pb_ds gives a time complexity of O(NlogN).
*/
typedef tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

int main(){
	int n,k;
	cin>>n>>k;
	ordered_set s;
	for(int i=1;i<=n;i++)
		s.insert(i);
	int it = 0; // pointer which will indicate the person that is to be eliminated.
	vector<int> ord; // This will contain the order of elimination.
	while(s.size() > 0){
		int i = s.size();
		int m = i;
		// If k is larger than the number of the remaining people, we will have to skip only k % size persons including the person where the pointer is at currently otherwise we skip k persons
		i = (k >= i) ? (k % i) : k;
		// We adjust the pointer to the next person that is to be eliminated
		it = (it + i) % m;
		ord.push_back(*s.find_by_order(it));
		s.erase(*s.find_by_order(it));
		// After elimination if pointer is at the end we need to change it to the beginning
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

/*
	Time complexity = O(NlogN)
*/