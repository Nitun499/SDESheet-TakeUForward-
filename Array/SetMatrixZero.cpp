#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>arr
#define vvi vector<vector<int>>arr
void helper(vector<vector<int>>&arr){
     int n=arr.size();
    int m=arr[0].size();
    //brute force approach
    //make a temp matrix and make all entry as 1
    //now again traverse original matrix and for a position where 0 found update coresponding row and col
    //in temp matirx as zero. Finlly again traverse the matrix and copy all the elements into actual matrix
   
    vector<vector<int>>temp(n,vector<int>(m,1));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(arr[i][j]==0){
                        //for row
                        for(int k=0;k<n;k++){
                            temp[k][j]=0;
                        }
                        //for col
                        for(int k=0;k<n;k++){
                            temp[i][k]=0;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    arr[i][j]=temp[i][j];
                }
            }
    

    //second approach more better than brute force approach
    //Make two vectors or hashmap(one for row and one for col) and traverse the original
    //matrix and if any block has 0 there (i,j) make that row[i]=true and col[j]=true
    //indicates that we have to update the value for that particular in row and col as well
        /*vector<bool>row(n,false),col(m,false);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(arr[i][j]==0){
                        row[i]=true;
                        col[j]=true;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(row[i]==true||col[j]==true){
                        arr[i][j]=0;
                    }
                }
            }
        */

    //Optimized approach
    //make two variables firstRow ,firstCol initialize as false
    //now traverse the firstrow and if any of cell is found to have 0 
    //mark firstRow as true same for firstCol mark that as well after traversing the first col
    //now traverse the matrix and if any of cell have 0 mark A[i][0]=0 && A[0][j]=0;
    //now traverse the matrix again from (1,1) till (n-1,m-1) and for every cell 
    //if any of (i,0)||(0,j)==0 mark current cell as 0
    //now check if firstRow variable is true make firstRow as 0 same for firstCol
     bool rowflag=false,colflag=false;
        for(int i=0;i<n;i++){
            if(arr[0][i]==0){
                rowflag=true;
            }
        }
        for(int i=0;i<m;i++){
            if(arr[i][0]==0){
                colflag=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    arr[0][j]=0;
                    arr[i][0]=0;
                }
            }
        }
         for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[0][j]==0||arr[i][0]==0){
                    arr[i][j]=0;
                }
            }
        }
        if(rowflag){
            for(int i=0;i<m;i++){
                arr[0][i]=0;
            }
        }
        if(colflag){
            for(int i=0;i<n;i++){
                arr[i][0]=0;
            }
        }


}

int main(){
    vector<vector<int>>mat={ {1, 0, 1},{1, 1, 1},{1, 0, 1} };
    helper(mat);
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }



            
   
    return 0;
}