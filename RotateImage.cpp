#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //first transpose of matrix
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //now reverse each row of matrix
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
}

int main(){
    
    vvi mat={{1,2,3},{4,5,6},{7,8,9}};
    rotate(mat);
    for(auto it:mat){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}