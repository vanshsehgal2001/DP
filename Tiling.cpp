#include <iostream>
using namespace std;

//RECURSION
int numWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return numWays(n-1)+numWays(n-2);
}

//MEMOIZATION
int modNumWays(int n,int *dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=modNumWays(n-1,dp)+modNumWays(n-2,dp);
    return dp[n];
}

//DP
int dpNumWays(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    // cout<<numWays(n);
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    // cout<<modNumWays(n,dp);
    cout<<dpNumWays(n);
    return 0;
}
