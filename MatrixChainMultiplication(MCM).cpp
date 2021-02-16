#include <iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int MCMRec(int *arr,int i,int j){
    if(i>=j){
        return 0;
    }
    int res=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int ans1=MCMRec(arr,i,k);
        int ans2=MCMRec(arr,k+1,j);
        int ans=ans1+ans2+(arr[i-1]*arr[k]*arr[j]);
        res=min(ans,res);
    }
    return res;
}

//MEMOIZATION
int MCMMemo(int *arr,int i,int j,int dp[100][100]){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int ans1=MCMMemo(arr,i,k,dp);
        int ans2=MCMMemo(arr,k+1,j,dp);
        int ans=ans1+ans2+(arr[i-1]*arr[k]*arr[j]);
        res=min(ans,res);
    }
    return dp[i][j]=res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // cout<<MCMRec(arr,1,n-1);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<MCMMemo(arr,1,n-1,dp);
    return 0;
}
