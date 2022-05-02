#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
vector<vector<int>> fourSum(vector<int>& nums, int target_main) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target=target_main-(nums[i]+nums[j]);
                int front=j+1;
                int back=n-1;
                while(front<back){
                    int sum=nums[front]+nums[back];
                    if(sum<target){
                        front++;
                    }else if(sum>target){
                        back--;
                    }else{
                        vector<int>quadruple={nums[i],nums[j],nums[front],nums[back]};
                        ans.push_back(quadruple);
                        //to avoid duplicate elements
                     while(front<back && nums[front]==quadruple[2]){
                            front++;
                        }
                        //to ignore duplicate elemets again and again
                        while(front<back && nums[back]==quadruple[3]){
                            back--;
                        }
                    }
                }
                //to avoid duplicate elements
                while(j+1<n && nums[j+1]==nums[j]){
                j++;
                }
            }
            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }    
        }
        return ans;
        
    }

int main(){
    vector<int>arr={-1,0,-1,2,0,-2};
    int target;
    cout<<"Enter target for which u want to find quadruple "<<endl;
    cin>>target;
    auto ans=fourSum(arr,target);
   
    return 0;
}