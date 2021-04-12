#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	vector<int> v(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int m = n*(n-1)/2;
	vector<pair<int, pair<int,int>>> v1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			v1.push_back(make_pair(v[i]+v[j],make_pair(i+1,j+1)));
		}
	}
	sort(v1.begin(),v1.end());
	// for(int i=0;i<m;i++)
	// 	cout<<v1[i].first<<" ----- "<<v1[i].second.first<<"    "<<v1[i].second.second<<endl;
	int a[4] = {0},f = 0, l1 = 0, r1 = m-1;
	while(l1 < r1){
		int temp = v1[l1].first + v1[r1].first;
		if(temp == x){
			break;
		}
		else if(temp < x)
			l1++;
		else
			r1--;
	}
	for(int l=l1;l<r1;l++){
		if(f == 1)
			break;
		for(int r=l+1;r<=r1;r++){
			int temp = v1[l].first + v1[r].first;
			if(temp == x){
				int i1 = v1[l].second.first;
				int j1 = v1[l].second.second;
				int i2 = v1[r].second.first;
				int j2 = v1[r].second.second;
				if((i1 != i2) && (i1 != j2) && (j1 != i2) && (j1 != j2)){
					a[0] = i1; a[1] = j1; a[2] = i2; a[3] = j2;
					f = 1;
					break;
				}
			}
		}
	}
	if(f == 0)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		sort(a,a+4);
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	}
	return 0;
}