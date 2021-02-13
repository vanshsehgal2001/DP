#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int countSubsetSumRec(int *arr,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(arr[n-1]>sum){
        return countSubsetSumRec(arr,n-1,sum);
    }
    return countSubsetSumRec(arr,n-1,sum)+countSubsetSumRec(arr,n-1,sum-arr[n-1]);
}

//MEMOIZATION
int countSubsetSumMemo(int *arr,int n,int sum,int dp[100][100]){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1]>sum){
        return dp[n][sum]=countSubsetSumMemo(arr,n-1,sum,dp);
    }
    return dp[n][sum]=countSubsetSumMemo(arr,n-1,sum,dp)+countSubsetSumMemo(arr,n-1,sum-arr[n-1],dp);
}

//BOTTOM-UP
int countSubsetSumBott(int *arr,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    // cout<<countSubsetSumRec(arr,n,sum);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<countSubsetSumMemo(arr,n,sum,dp);
    cout<<countSubsetSumBott(arr,n,sum);
    return 0;
}
