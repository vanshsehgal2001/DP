#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

//RECURSION
int coinChange2Rec(int *coins,int n,int sum){
    if(n==0){
        if(sum==0){
            return INT_MAX;
        }
        return 0;
    }
    if(n==1){
        if(sum%coins[0]==0){
            return sum/coins[0];
        }
        return INT_MAX;
    }
    if(sum>=coins[n-1]){
        return min(coinChange2Rec(coins,n-1,sum),1+coinChange2Rec(coins,n,sum-coins[n-1]));
    }
    return coinChange2Rec(coins,n-1,sum);
}

//MEMOIZATION
int coinChange2Memo(int *coins,int n,int sum,int dp[][100]){
    if(n==0){
        if(sum==0){
            return INT_MAX-1;
        }
        return 0;
    }
    if(n==1){
        if(sum%coins[0]==0){
            return sum/coins[0];
        }
        return INT_MAX-1;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(sum>=coins[n-1]){
        return dp[n][sum]=min(coinChange2Memo(coins,n-1,sum,dp),1+coinChange2Memo(coins,n,sum-coins[n-1],dp));
    }
    return dp[n][sum]=coinChange2Memo(coins,n-1,sum,dp);
}

//BOTTOM-UP
int coinChange2Bott(int *coins,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=sum;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int i=1;i<=sum;i++){
        if(i%coins[0]==0){
            dp[1][i]=i/coins[0];
        }
        else{
            dp[1][i]=INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=coins[i-1]){
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
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
    cout<<coinChange2Rec(coins,n,sum);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<coinChange2Memo(coins,n,sum,dp);
    // cout<<coinChange2Bott(coins,n,sum);
    return 0;
}
