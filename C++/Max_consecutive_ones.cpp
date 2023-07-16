#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int> arr){
	int cnt=0,max_cnt=INT_MIN;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==1){
			cnt++;
			max_cnt=max(cnt,max_cnt);
		}
		else{
			cnt=0;
		}
	}
	return max_cnt;
}
int main(){
	vector<int> arr={1,1,0,1,1,1,0};
	int cnt=maxConsecutiveOnes(arr);
	cout<<"Max consecutive ones "<<"\n";
	cout<<cnt;
	return 0;
}
