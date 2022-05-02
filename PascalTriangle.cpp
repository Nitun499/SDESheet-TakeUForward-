#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr

vector<vector<int>> helper(int n){
     vector<vector<int>>ans;
        vector<int>prev(1,1);
        ans.push_back(prev);
        for(int i=1;i<n;i++){
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=prev[j-1]+prev[j];
            }
            ans.push_back(temp);
            prev=temp;
        }
        return ans;
}
int main(){
    
   int n;
   cin>>n;
   
   auto ans=helper(n);
   for(auto it:ans){
       for(auto ele:it){
           cout<<ele<<" ";
       }
       cout<<"\n";
   }
   
    return 0;
}