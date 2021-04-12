#include<iostream>
#include<string>
using namespace std;
string repeat(char a, int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}
string reverse_string(string s){
	string s1 = "";
	int n = s.size();
	for(int i=n-1;i>=0;i--){
		s1 = s1 + s[i];
	}
	return s1;
}
int main(){
	string s;
	//cout<<string(a[i]/2, 'A' + 1)<<endl;
	cin>>s;
	int n = s.size();
	int a[26] = {0};
	for(int i=0;i<n;i++){
		a[s.at(i) - 'A'] += 1;
	}
	int odd_cnt = 0, even_cnt = 0;
	for(int i=0;i<26;i++){
		if(a[i] > 0){
			if(a[i] % 2 == 0)
				even_cnt++;
			else
				odd_cnt++;
		}
	}
	if(n % 2 == 0){
		if(odd_cnt > 0)
			cout<<"NO SOLUTION"<<endl;
		else{
			string s1 = "";
			for(int i=0;i<26;i++){
				if(a[i] > 0){
					s1 = s1 + string(a[i]/2, 'A' + i);
				}
			}
			s1 = s1 + reverse_string(s1);
			cout<<s1<<endl;
		}
	}
	else{
		if(odd_cnt != 1)
			cout<<"NO SOLUTION"<<endl;
		else{
			string s1 = "";
			char ch;
			for(int i=0;i<26;i++){
				if(a[i] > 0){
					if(a[i] % 2 == 0)
						s1 = s1 + string(a[i]/2, 'A' + i);
					else{
						ch = 'A' + i;
						s1 = s1 + string((a[i]-1)/2, 'A' + i);
					}
				}
			}
			s1 = s1 + ch + reverse_string(s1);
			cout<<s1<<endl;
		}
	}
	return 0;
}