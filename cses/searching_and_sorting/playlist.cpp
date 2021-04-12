#include<iostream>
#include<vector>
#include<map>
using namespace std;

//const int nxM = 1e9;

int main(){
	int n;
	cin>>n;
	
	map<int ,int> mp;
	int a[n] = {0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l = 0, r = 0, cnt = 0, max_cnt = 0;
	while(r < n){
		if(mp.find(a[r]) == mp.end()){
			cnt++;
			mp[a[r]] = r;
			r++;
		}
		else{
			if(mp[a[r]] == r || mp[a[r]] < l){
				cnt++;
				mp[a[r]] = r;
				r++;	
			}
			else{
				if(cnt > max_cnt)
					max_cnt = cnt;
				cnt = cnt - (mp[a[r]] - l +1);
				l = mp[a[r]] + 1;
			}
		}
	}
	if(cnt > max_cnt)
		max_cnt = cnt;
	cout<<max_cnt<<endl;
	return 0;
}