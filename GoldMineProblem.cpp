#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=100;

int getMaxGold(int gold[][MAX],int m,int n){
    int table[m][n];
    memset(table,0,sizeof(table));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            int option1= (i==n-1) ? 0 : table[j][i+1];
            int option2= (j==0 || i==n-1) ? 0 : table[j-1][i+1];
            int option3= (j==m-1 || i==n-1) ? 0 : table[j+1][i+1];
            
            table[j][i]= gold[j][i]+ (max(option3,max(option2,option1)));
        }
    }
    int ans=table[0][0];
    for(int i=1;i<m;i++){
        ans=max(ans,table[i][0]);
    }
    return ans;
}

int main()
{
    int gold[MAX][MAX]= { {1, 3, 1, 5}, 
                          {2, 2, 4, 1}, 
                          {5, 0, 2, 3}, 
                          {0, 6, 1, 2} 
                        }; 
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n); 
    return 0;
}
