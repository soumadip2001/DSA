#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
	int i=l;
	int j=mid+1;
	int k=l;
	int b[100000];
	while(i<=mid && j<=r)
	{
		if(arr[i]>=arr[j])
		{
			b[k]=arr[j];
			j++;
		}
		else
		{
			b[k]=arr[i];
			i++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=r)
		{
			b[k]=arr[j];
			k++;
			j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	for(int i=0;i<=r;i++)
	{
		arr[i]=b[i];
	}
	
}
void merge_sort(int arr[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,r);
		merge(arr,l,mid,r);		
	}
	
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";	
	}	
	return 0;
}
