#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
long long __merge(int *arr,int low,int mid,int high){
	vector<long long>temp(high-low+1,0);
	int i=low,j=mid+1;
	int k=0;
	long long ans=0;
	while(i<=mid && j<=high){
		if(arr[i]>arr[j]){
			ans+=(mid-i+1);
			temp[k++]=arr[j++];
		}else{
			temp[k++]=arr[i++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=high){
		temp[k++]=arr[j++];
	}
	for(int i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}
	return ans;
}
long long mergesort(int* arr,long long low,long long high){
	long long inv=0;
	if(low<high){
		long long mid=low+(high-low)/2;
		inv=mergesort(arr,low,mid);
		inv+=mergesort(arr,mid+1,high);
		inv+=__merge(arr,low,mid,high);
	}
	return inv;
}
long long getInversions(int *arr, int n){
    // Write your code here.
	return mergesort(arr,0,n-1);
}


int main(){
    int arr[]={1,2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
   int ans=getInversions(arr,size);
    return 0;
}