#include<bits/stdc++.h>
using namespace std;
long long kadanes_algo(vector<int> arr){
	long long max_sum=LONG_MIN;
	long long sum=0;
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
		if(sum>max_sum){
			max_sum=sum;
		}
		if(sum<0){
			sum=0;
		}
	}
	return max_sum;
}
int main(){
	vector<int> arr;
	int a=0,n=0;
	cin>>n;
	while(n--){
		cin>>a;
		arr.push_back(a);
	}
	long long max_sum=kadanes_algo(arr);
	cout<<"max_sum "<<max_sum;
	return 0;
}
