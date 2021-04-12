#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l = 0, r = 0,maximum = 0, len = s.size();
	while(r < len){
		while(r < len && s[r] == s[l])
			r++;
		if(r-l > maximum)
			maximum = r-l;
		l = r;
	}
	cout<<maximum<<endl;
	return 0;
}