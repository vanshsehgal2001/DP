#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int knapsackRec(int *weight,int *value,int maxWeight,int n){
    if(n==0 || maxWeight==0){
        return 0;
    }
    if(weight[n-1]>maxWeight){
        return knapsackRec(weight,value,maxWeight,n-1);
    }
    else{
        return max(value[n-1]+knapsackRec(weight,value,maxWeight-weight[n-1],n-1),knapsackRec(weight,value,maxWeight,n-1));
    }
}

//MEMOIZATION
int knapsackMemo(int *weight,int *value,int maxWeight,int n,int dp[100][100]){
    if(n==0 || maxWeight==0){
        return 0;
    }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    if(weight[n-1]>maxWeight){
        return dp[n][maxWeight]=knapsackMemo(weight,value,maxWeight,n-1,dp);
    }
    else{
        return dp[n][maxWeight]=max(value[n-1]+knapsackMemo(weight,value,maxWeight-weight[n-1],n-1,dp),knapsackMemo(weight,value,maxWeight,n-1,dp));
    }
}

//BOTTOM-UP
int knapsackIter(int *weight,int *value,int maxWeight,int n){
    int dp[n+1][maxWeight+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=maxWeight;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][maxWeight];
}

int main()
{
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int maxWeight;
    cin>>maxWeight;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<knapsackRec(weight,value,maxWeight,n);
    // cout<<knapsackMemo(weight,value,maxWeight,n,dp);
    cout<<knapsackIter(weight,value,maxWeight,n);
    return 0;
}
