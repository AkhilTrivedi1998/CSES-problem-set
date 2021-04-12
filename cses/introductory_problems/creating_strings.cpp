#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
	string s;
	int n = 0;
	vector<string> v;
	cin>>s;
	sort(s.begin(),s.end());
	do{
		v.push_back(s);
		n++;
	}while(next_permutation(s.begin(),s.end()));
	// while(next_permutation(s.begin(),s.end())){
	// 	v.push_back(s);
	// 	n++;
	// }
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<v[i]<<endl;
	return 0;
}