#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void gen_permu(vector<int> &arr,int n,int idx){
//	for(int i=0;i<n;i++){
//		cout<<arr[i];
//	}
//	cout<<"\n";
	if(idx==arr.size()){
		ans.push_back(arr);
		return;
	}
	for(int i=idx;i<n;i++){
		if(i!=idx && arr[idx]==arr[i])
			continue;
		swap(arr[idx],arr[i]);
		gen_permu(arr,n,idx+1);
		swap(arr[i],arr[idx]);
		
	}
//	return ;
}
int main(){
	vector<int> arr;
	int n=3,a=0;
	cout<<"Enter the size of array ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	n=arr.size();
	gen_permu(arr,n,0);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
