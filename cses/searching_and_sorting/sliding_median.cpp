#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

/*
	We need to use multiset here beacause elements might repeat.
	To simulate multiset in policy based data structure we use pair with second element of pair being the unique index value of the element.
*/
typedef tree<pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

int main(){
	int n,k;
	cin>>n>>k;
	int a[n] = {0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	ordered_set s;

	// We first insert k values into our pd_ds.
	for(int i=0;i<k;i++)
		s.insert(make_pair(a[i],i));

	/* It is given that for even number of elements we take the smaller element as median.
	   So for both even and odd number of elements the index of median is given by the formulae (k-1)/2 */
	int j = (k-1)/2;

	// There will be n-k+1 windows so we iterate that many number of times
	for(int i=0;i<(n-k+1);i++){
		// Each time we find the median for the window and assign it to b array
		auto it = s.find_by_order(j);

		// we print the result for each of the windows.
		if(i == n-k)
			cout<<(*it).first<<endl;
		else
			cout<<(*it).first<<" ";
		
		/*
			Each time we delete the first element of the window and add the element of the array which is next in line
			We need not have to do it for the last iteration
		*/
		if(i != n-k){
			s.erase(make_pair(a[i],i));
			s.insert(make_pair(a[i+k],i+k));
		}
	}
	return 0;
}

/*
	Time Complexity: O(NlogK)
	Auxiliary Space: O(K)
*/
