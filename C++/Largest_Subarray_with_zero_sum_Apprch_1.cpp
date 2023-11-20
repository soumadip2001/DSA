#include<bits/stdc++.h>
using namespace std ;
int main(){
	int lcount = 0;
	int cnt = 0; 
	vector<int> arr = {9, -3, 3, -1, 6, -5};
	for(int i=0;i<arr.size();i++){
		int sum=arr[i];
		for(int j=i+1;j<arr.size();j++){
			sum+=arr[j];
			if(sum==0){
				cnt=max(cnt,j-i+1);
			}
		}
	}
	cout<<"larget subarray with zero sum "<<cnt;
	return 0;
}
