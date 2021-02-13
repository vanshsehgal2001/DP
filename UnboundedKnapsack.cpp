#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

//RECURSION
int unboundedKnapsackRec(int *weight,int *value,int n,int maxWeight){
    if(n==0 || maxWeight==0){
        return 0;
    }
    if(weight[n-1]<=maxWeight){
        return max(unboundedKnapsackRec(weight,value,n-1,maxWeight),value[n-1]+unboundedKnapsackRec(weight,value,n,maxWeight-weight[n-1]));
    }
    return unboundedKnapsackRec(weight,value,n-1,maxWeight);
}

//MEMOIZATION
int unboundedKnapsackMemo(int *weight,int *value,int n,int maxWeight,int dp[100][100]){
    if(n==0 || maxWeight==0){
        return 0;
    }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    if(weight[n-1]<=maxWeight){
        return dp[n][maxWeight]=max(unboundedKnapsackMemo(weight,value,n-1,maxWeight,dp),value[n-1]+unboundedKnapsackMemo(weight,value,n,maxWeight-weight[n-1],dp));
    }
    return dp[n][maxWeight]=unboundedKnapsackMemo(weight,value,n-1,maxWeight,dp);
}

//BOTTOM-UP
int unboundedKnapsackBott(int *weight,int *value,int n,int maxWeight){
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
                dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i][j-weight[i-1]]);
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
    // cout<<unboundedKnapsackRec(weight,value,n,maxWeight);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<unboundedKnapsackMemo(weight,value,n,maxWeight,dp);
    cout<<unboundedKnapsackBott(weight,value,n,maxWeight);
    return 0;
}
