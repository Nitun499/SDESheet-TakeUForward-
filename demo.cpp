#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
bool helper(string &a){
    unordered_set<char>st(begin(a),end(a));
    return a.size()==st.size();
}

int main(){
    string ab="abcd";
    int n=ab.size();
    for(int i=0;i<n;i++){
        for(int len=1;len<=n-i;len++){
            cout<<ab.substr(i,len)<<endl;
        }
    }
   
    return 0;
}