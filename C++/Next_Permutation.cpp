#include<bits/stdc++.h>
using namespace std;
void next_permu(vector<int> &arr){
	int i=arr.size()-2,idx=0;
	while(i>=0){
		if(arr[i]<arr[i+1]){
			idx=i;
			break;
		}
		i--;
	}
	if(i<0){
		reverse(arr.begin(),arr.end());
		return;
	}
	for(int i=arr.size()-1;i>idx;i--){
		if(arr[i]>arr[idx]){
			swap(arr[i],arr[idx]);
			break;
		}
	}
	reverse(arr.begin()+idx+1,arr.end());
}
int main(){
	int n=0;
	cout<<"length of number ";
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	next_permu(arr);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
	}
	return 0;
}
