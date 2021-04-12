#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	vector<int> v1(v.begin(),v.end());
	sort(v.begin(),v.end());
	int val1 = -1,val2 = -1,val3 = -1, f = -1;
	for(int i=0;i<n-2;i++){
		if(f != -1)
			break;
		for(int j=i+1;j<n-1;j++){
			if(v[i] + v[j] >= x)
				break;
			int d = x - (v[i] + v[j]);
			if(binary_search(v.begin()+j+1,v.end(),d)){
				val1 = v[i]; val2 = v[j]; val3 = d; 
				f = 0;
				break;
			}
		}
	}
	if(f == -1)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		int a[3] = {0, 0, 0};
		for(int i=0;i<n;i++){
			if(v1[i] == val1 && a[0] == 0)
				a[0] = i+1;
			else if(v1[i] == val2 && a[1] == 0)
				a[1] = i+1;
			else if(v1[i] == val3 && a[2] == 0)
				a[2] = i+1;
		}
		sort(a,a+3);
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
	return 0;
}