#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int a[26] = {0}, c = 0;
	for(char d : s)
		a[d - 'A']++;
	for(int i=0;i<26;i++){
		if(a[i] & 1)
			c++;
	}
	if(c > 1)
		cout<<"NO SOLUTION"<<endl;
	else{
		string t;
		for(int i=0;i<26;i++){
			if(a[i] & 1 ^ 1){
				for(int j=0;j<a[i]/2;j++)
					t += (char)('A' + i);
			}
		}
		cout<<t;
		for(int i=0;i<26;i++){
			if(a[i] & 1){
				for(int j=0;j<a[i];j++)
					cout<<(char)('A' + i);
			}
		}
		reverse(t.begin(),t.end());
		cout<<t<<endl;
	}
	return 0;
}