//sort 0,1,2 optimal approach
#include<bits/stdc++.h>
using namespace std;
void sort012(vector<int> &arr){
	int low=0,mid=0,end=arr.size()-1;
	while(mid<=end){
		if(arr[mid]==0){
			swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		else if(arr[mid]==2){
			swap(arr[mid],arr[end]);
			end--;
		}
		else{
			mid++;
		}
	}
	for(auto &itr:arr){
		cout<<itr<<" ";
	}
}
int main(){
	vector<int> arr;
	int n=0,a=0;
	cin>>n;
	while(n--){
		cin>>a;
		arr.push_back(a);
	}
	sort012(arr);
	return 0;
}
