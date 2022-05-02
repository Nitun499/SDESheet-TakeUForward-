#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
 int merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp(high-low+1,0);
        int j=mid+1;
        int ans=0;
        for(int i=low;i<=mid;i++){
            while(j<=high&& arr[i]>2*(long)arr[j]){
                j++;
            }
            ans+=(j-(mid+1));
        }
         int i=low;
        j=mid+1;
        int k=0;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
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
    int mergesort(vector<int>&arr,int low,int high){
        if(low>=high){
            return 0;
        }
        int mid=low+(high-low)/2;
        int ans=0;
        ans=mergesort(arr,low,mid);
        ans+=mergesort(arr,mid+1,high);
        ans+=merge(arr,low,mid,high);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }

int main(){
    
   vector<int>arr={1,3,2,3,1};
   int ans=reversePairs(arr);
   cout<<ans;
    return 0;
}