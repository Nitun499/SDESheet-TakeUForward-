#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
int findDuplicate(vector<int>& nums) {

       int n=nums.size();
        int ans=0;
        //Not Brute force but better than that
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second>1){
                ans=it.first;
                break;
            }
        }
        return ans;
        //Optimized Approach
        int i=0;
        while(i<n){
            int correct=nums[i]-1;
            if(nums[i]!=nums[correct]){
                swap(nums[i],nums[correct]);
            }else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i]){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }

int main(){
    vector<int>arr={1,3,4,2,2};
    auto ans= findDuplicate(arr);
   
    return 0;
}