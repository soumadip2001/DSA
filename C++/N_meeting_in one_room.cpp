#include<bits/stdc++.h>
using namespace std;
struct meeting{
	int start;
	int end;
	int pos;
};
class solution{
	public:
	bool static comparator(struct meeting m1,meeting m2){
		if(m1.end<m2.end)
			return true;
		else if(m1.end>m2.end)
			return false;
		else if(m1.pos<m2.pos)		//when starting time and end time is equal then sort according to there position
			return true;
		else
			return false;
	}
	void maxMeeting(vector<int> &start,vector<int> &end,int n){
//		struct meeting meet[n];
		vector<meeting> meet(n);
		for(int i=0;i<n;i++){
			meet[i].start=start[i];
			meet[i].end=end[i];
			meet[i].pos=i+1;
		}
//		sort(meet,meet+n,comparator);
		sort(meet.begin(),meet.end(),comparator);
		int temp_end=INT_MAX,temp_start=INT_MIN;
		int cnt=0;
		vector<int> ans;
		ans.push_back(meet[0].pos);
		temp_end=meet[0].end;
		for(int i=1;i<n;i++){
			if(meet[i].start>temp_end){
				ans.push_back(meet[i].pos);
				cout<<meet[i].pos<<" ";
				temp_end=meet[i].end;
			}
		}
		cout<<"output to meetings "<<"\n";
		
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
	}
};
int main(){
	solution obj;
	int n=6;
	vector<int> start={1,3,0,5,8,5};
	vector<int> end={2,4,5,7,9,9};
	obj.maxMeeting(start,end,n);
	return 0;
}
