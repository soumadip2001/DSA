#include<bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr,int l,int mid,int r){
	int n=mid-1,inv=0;
	vector<int> k;
	while(l<=n && mid<=r){
		if(arr[l]>arr[mid]){
			k.push_back(arr[mid]);
			mid++;
			inv+=(n-l+1);
		}
		else{
			k.push_back(arr[l]);
			l++;
		}
	}
		while(mid<=r){
			k.push_back(arr[mid]);
			mid++;
		}
		while(l<=n){
			k.push_back(arr[mid]);
			l++;
		}
	for(int j=l;j<=r;j++){
		arr[j]=k[j-l];
	}
	return inv;
	
}
int merge_sort(vector<int> &arr,int l,int r){
	int inv1=0;
	if(l>=r){
		return inv1;
	}
	int mid=(l+r)/2;
	inv1+=merge_sort(arr,l,mid);
	inv1+=merge_sort(arr,mid+1,r);
	inv1+=merge(arr,l,mid+1,r);
	return inv1;
}
int main(){
	int n=0;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int a;	cin>>a;
		arr.push_back(a);
	}
	int t_inv=merge_sort(arr,0,n-1);
	cout<<"total inversion "<<t_inv<<"\n";
	cout<<"sorted array ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
