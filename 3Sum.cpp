#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            int target=-nums[i];
            int front=i+1;
            int back=n-1;
            if(target<0){
                break;
            }
            while(front<back){
                int sum=nums[front]+nums[back];
                if(sum<target){
                    front++;
                }else if(sum>target){
                    back--;
                }else{
                    vector<int>triplet={nums[i],nums[front],nums[back]};
                    ans.push_back(triplet);
                    while(front<back && nums[front]==triplet[1]){
                        front++;
                    }
                    while(front<back && nums[back]==triplet[2]){
                        back--;
                    }
                }
            }
            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }
        }
        return ans;
    }
int main(){
    vector<int>arr={-1,0,1,2,-1,-4};
    auto ans=threeSum(arr);
    for(auto it:ans){
        auto temp_vec=it;
        for(auto ele:temp_vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}