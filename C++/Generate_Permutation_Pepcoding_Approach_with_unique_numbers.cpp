//Only with unique numbers

#include<bits/stdc++.h>
using namespace std;
string permu(int n,int total_permu){
	string num="";
	while(n!=0){
		string s=to_string(n%10);
		num+=s;
		n=n/10;
	}
	reverse(num.begin(),num.end());
	int len=num.length(),rem=0;
	string ans="";
	while(len>=1){
		rem=total_permu%len;
		ans+=num[rem];
		/*
		Delete 1 character after rem index(including) means deleting rem index basically because of 1
		*/
		num.erase(rem,1);	
		len--;
	}
	return ans;
}
int factorial(int n){
	int cnt=0;
	while(n!=0){
		n=n/10;
		cnt++;
	}
	int fact=1;
	while(cnt!=0){
		fact*=cnt;
		cnt--;
	}
	return fact;
}
int main(){
	int n=0;
	vector<string> arr;
	cin>>n;
	int total_permu=factorial(n)-1;
	while(total_permu>=0){
		arr.push_back(permu(n,total_permu));
		total_permu--;
	}
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<"\n";
	}
	return 0;
}
