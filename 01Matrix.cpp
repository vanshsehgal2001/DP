#include<climits>
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        //TLE SOLUTION
        
        // vector<int> row;
        // vector<int> col;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==0){
        //             row.push_back(i);
        //             col.push_back(j);
        //         }
        //     }
        // }
        // vector<vector<int>> output=matrix;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==0){
        //             continue;
        //         }
        //         int x=i;
        //         int y=j;
        //         int dist=1000000;
        //         for(int k=0;k<row.size();k++){
        //             int a=x-row[k];
        //             int b=y-col[k];
        //             if(x<row[k]){
        //                 a=-a;    
        //             }
        //             if(y<col[k]){
        //                 b=-b;
        //             }
        //             dist=min(dist,a+b);
        //         }
        //         output[i][j]=dist;
        //     }
        // }
        // return output;
        
        //OPTIMISED DP APPROACH(KINDA)
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    continue;
                }
                int top=INT_MAX/2;
                int left=INT_MAX/2;
                if(i>0){
                    top=matrix[i-1][j];
                }
                if(j>0){
                    left=matrix[i][j-1];
                }
                matrix[i][j]=1+min(top,left);
            }
        }
        
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(matrix[i][j]==0){
                    continue;
                }
                int bottom=INT_MAX/2;
                int right=INT_MAX/2;
                if(i<matrix.size()-1){
                    bottom=matrix[i+1][j];
                }
                if(j<matrix[0].size()-1){
                    right=matrix[i][j+1];
                }
                matrix[i][j]=min(matrix[i][j],1+min(bottom,right));
            }
        }
        return matrix;
    }
};
