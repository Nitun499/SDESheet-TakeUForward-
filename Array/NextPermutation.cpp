#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
void nextPermutation(vector<int>& nums) {
        int smallindex=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                smallindex=i-1;
                break;
            }
        }
        if(smallindex==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int greaterindex=-1;
        int k=n-1;
        while(k>smallindex){
            if(nums[k]>nums[smallindex]){
                greaterindex=k;
                break;
            }
            k--;
        }
        swap(nums[smallindex],nums[greaterindex]);
        reverse(nums.begin()+smallindex+1,nums.end());
    }

int main(){
    vector<int>arr={4,3,7,6,5};
    nextPermutation(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
   
    return 0;
}