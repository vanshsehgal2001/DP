#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
bool subsetSumRec(int *arr,int n,int sum){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1]>sum){
        return subsetSumRec(arr,n-1,sum);
    }
    else{
        return subsetSumRec(arr,n-1,sum-arr[n-1])||subsetSumRec(arr,n-1,sum);
    }
}

//MEMOIZATION
bool subsetSumMemo(int *arr,int n,int sum,bool dp[100][100]){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(dp[n][sum]!=false){
        return dp[n][sum];
    }
    if(arr[n-1]>sum){
        return dp[n][sum]=subsetSumMemo(arr,n-1,sum,dp);
    }
    else{
        return dp[n][sum]=subsetSumMemo(arr,n-1,sum-arr[n-1],dp)||subsetSumMemo(arr,n-1,sum,dp);
    }
}

//BOTTOM-UP
bool subsetSumBott(int *arr,int n,int sum){
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;    
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }    
            else{
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
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
    // if(subsetSumRec(arr,n,sum)){
    //     cout<<"Yes"<<endl;
    // }
    // else{
    //     cout<<"No"<<endl;
    // }
    bool dp[100][100];
    memset(dp,false,sizeof(dp));
    // if(subsetSumMemo(arr,n,sum,dp)){
    //     cout<<"Yes"<<endl;
    // }
    // else{
    //     cout<<"No"<<endl;
    // }
    if(subsetSumBott(arr,n,sum)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
