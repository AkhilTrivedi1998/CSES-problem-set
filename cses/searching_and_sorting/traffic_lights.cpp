#include<iostream>
#include<set>
using namespace std;
int main(){
	set<int> s1;
	multiset<int> s2;
	int n,x;
	cin>>x>>n;
	int p[n] = {0};
	for(int i=0;i<n;i++)
		cin>>p[i];
	s1.insert(0);
	s1.insert(x);
	s2.insert(x);
	for(int i=0;i<n;i++){
		auto it2 = s1.lower_bound(p[i]);
		auto it1 = it2;
		it2--;
		auto it3 = s2.find((*it1) - (*it2));
		s2.erase(it3);
		s2.insert(p[i] - (*it2));
		s2.insert((*it1) - p[i]);
		s1.insert(p[i]);
		auto it4 = s2.end();
		it4--;
		cout<<(*it4)<<endl;
	}
	return 0;
}