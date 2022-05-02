#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
 int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int curr=0;
        for(auto it:nums){
            curr+=it;
            maxsum=max(maxsum,curr);
            if(curr<0){
                curr=0;
            }
        }
        return maxsum;
    }

int main(){
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    auto ans=maxSubArray(arr);
    cout<<ans;
   
    return 0;
}