#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
 int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        int lsf=prices[0];
        int len=prices.size();
        for(int i=1;i<len;i++){
            lsf=min(lsf,prices[i]);
            ans=max(ans,prices[i]-lsf);
        }
        return (ans==INT_MIN?0:ans);
    }

int main(){
    vector<int>arr={7,1,5,3,6,4};
    auto ans=maxProfit(arr);
    cout<<ans;
   
    return 0;
}