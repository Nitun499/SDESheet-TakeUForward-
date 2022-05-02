#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maj){
                cnt++;
            }else if(cnt==0){
                cnt=1;
                maj=nums[i];
            }else{
                cnt--;
            }
        }
        return maj;
    }

int main(){
    vector<int>arr={3,2,3};
    auto ans=majorityElement(arr);
    cout<<ans;
   
    return 0;
}