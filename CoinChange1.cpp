#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

//RECURSION
int coinChange1Rec(int *coins,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(sum>=coins[n-1]){
        return coinChange1Rec(coins,n-1,sum)+coinChange1Rec(coins,n,sum-coins[n-1]);
    }
    return coinChange1Rec(coins,n-1,sum);
}

//MEMOIZATION
int coinChange1Memo(int *coins,int n,int sum,int dp[][100]){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(sum>=coins[n-1]){
        return dp[n][sum]=coinChange1Memo(coins,n-1,sum,dp)+coinChange1Memo(coins,n,sum-coins[n-1],dp);
    }
    return dp[n][sum]=coinChange1Memo(coins,n-1,sum,dp);
}

//BOTTOM-UP
int coinChange1Bott(int *coins,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=coins[i-1]){
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int sum;
    cin>>sum;
    // cout<<coinChange1Rec(coins,n,sum);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<coinChange1Memo(coins,n,sum,dp);
    cout<<coinChange1Bott(coins,n,sum);
    return 0;
}
