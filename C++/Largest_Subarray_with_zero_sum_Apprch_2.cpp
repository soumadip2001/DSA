#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> arr={9, -3, 3, -1, 6, -5};
	unordered_map<int,int> m;
	int cnt = 0;
	int sum =0;
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
		if(sum == 0){
			cnt= i+1;
		}
		else if(m.find(sum) != m.end()){
			cnt= max(cnt,i - m[sum]);
		}
		else{
			m[sum]= i;
		}
	}
	cout<<"largest subarray sum "<<cnt;
	return 0;
}
