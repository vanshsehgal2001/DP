#include <iostream>
using namespace std;
const int mm=1000;
const int nn=1000;

//RECURSION
int gridTraveller(int m,int n){
    if(m==1 && n==1){
        return 1;
    }
    if(m==0 || n==0){
        return 0;
    }
    return gridTraveller(m-1,n)+gridTraveller(m,n-1);
}

//MEMOIZATION
int modGridTraveller(int m,int n,int dp[mm][nn]){
    if(m==1 && n==1){
        return 1;
    }
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    dp[m][n]=modGridTraveller(m-1,n,dp)+modGridTraveller(m,n-1,dp);
    return dp[m][n];
}

int main()
{
    int m,n;
    cin>>m>>n;
    // cout<<gridTraveller(m,n);
    int dp[mm][nn];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<modGridTraveller(m,n,dp);
    return 0;
}
