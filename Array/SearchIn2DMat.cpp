#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
//rows are sorted and each first element of row is greater than the last 
//element of previous row
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }else if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }

int main(){
    string temp="abcd";
    cout<<temp.substr(0,5);
   
    return 0;
}