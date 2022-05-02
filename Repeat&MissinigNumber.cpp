#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
vector<int> repeatedNumber(const vector<int> & A) {
    vector<int>arr=A;
    vector<int>ans;
    int i=0;
    while(i<arr.size()){
        int correct=arr[i]-1;
        if(arr[i]!=arr[correct]){
            int temp=arr[i];
            arr[i]=arr[correct];
            arr[correct]=temp;
        }else{
            i++;
        }
    }
    for(int i=0;i<arr.size();i++){
        if(i+1!=arr[i]){
            ans.push_back(arr[i]);
            ans.push_back(i+1);
            break;
        }
    }
    
    return ans;
}

int main(){
    
   vector<int>arr={3,1,2,5,3};
   auto ans=repeatedNumber(arr);
    return 0;
}